using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lightController : MonoBehaviour
{
    public Light[] sl;
    int[] intensities = new int[9];
    int[] newIntensities = new int[9];
    private int sensitivity,nrOfCycles;
    // Use this for initialization
    void Start ()
    {
        InvokeRepeating("UpdateLights", 0.3f, 0.3f);
        sensitivity = 1;
        nrOfCycles = 0;
    }

    // Update is called once per frame
    void UpdateLights()
    {
        // We get the new intensities.
        for (int i = 1; i <= 8; i++)
            newIntensities[i] = UDP.intensities[i];

        // For each of the lights.
        for (int i = 1; i <= 8; i++)
        {
            // If the new intensity is bigger then the old one by the sensitivity we have set.
            if (newIntensities[i] > intensities[i]+sensitivity)
            {
                // We increase the light intensity.
                sl[i].intensity += (newIntensities[i] - intensities[i])/sensitivity;
                // We increase the number of cycles
                nrOfCycles++;
                // If we've had multiple cycles of increased intensity, we need to increase the sensitivity.
                if (nrOfCycles == 3)
                    sensitivity++;
            }
            else
            {
                if (sl[i].intensity > 0)
                {
                    // We decrease the intensity.
                    sl[i].intensity--;
                    // We decrease the number of cycles.
                    nrOfCycles--;
                    // If we've had multiple decreases, we need to lower the sensitivity.
                    if (nrOfCycles == -3)
                        sensitivity--;
                }
            }
            intensities[i] = newIntensities[i];
        }
    }

    private void Update()
    {
        
    }
}
