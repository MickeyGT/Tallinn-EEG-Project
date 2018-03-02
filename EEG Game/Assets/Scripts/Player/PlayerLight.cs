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
        light.intensity = UDP.power - 1;
        if (UDP.power >= 50)
            halo.enabled = true; // false
        else
            halo.enabled = false;
    }
}
