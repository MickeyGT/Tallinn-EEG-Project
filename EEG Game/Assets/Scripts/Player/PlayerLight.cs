using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerLight : MonoBehaviour {

    private Light light;
    private Behaviour halo;
    // Use this for initialization
    void Start ()
    {
        light = GetComponent<Light>();
        halo = (Behaviour)GetComponent("Halo");
    }
	
	// Update is called once per frame
	void Update ()
    {
        // Change the intensity based on the power from UDP.
        light.intensity = UDP.power * 2 - 1;
        // If the power is over 50, the player gets a "Super-Sayian Halo".
        if (UDP.power >= 50)
            halo.enabled = true;
        else
            halo.enabled = false;
    }
}
