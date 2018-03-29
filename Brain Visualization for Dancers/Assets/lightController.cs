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
        for (int i = 1; i <= 8; i++)
            newIntensities[i] = UDP.intensities[i];

        for (int i = 1; i <= 8; i++)
        {
            if (newIntensities[i] > intensities[i]+sensitivity)
            {
                sl[i].intensity += (newIntensities[i] - intensities[i])/sensitivity;
                nrOfCycles++;
                if (nrOfCycles == 3)
                    sensitivity++;
            }
            else
            {
                if (sl[i].intensity > 0)
                {
                    sl[i].intensity--;
                    nrOfCycles--;
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
