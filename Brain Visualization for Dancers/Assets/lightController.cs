using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lightController : MonoBehaviour
{
    public Light sl1,sl2,sl3,sl4,sl5,sl6,sl7,sl8; // spotlights

	// Use this for initialization
	void Start ()
    {
        Light sl1 = GetComponent ("Spotlight1" ) as Light;
        Light sl2 = GetComponent("Spotlight2") as Light;
        Light sl3 = GetComponent("Spotlight3") as Light;
        Light sl4 = GetComponent("Spotlight4") as Light;
        Light sl5 = GetComponent("Spotlight5") as Light;
        Light sl6 = GetComponent("Spotlight6") as Light;
        Light sl7 = GetComponent("Spotlight7") as Light;
        Light sl8 = GetComponent("Spotlight8") as Light;

    }
	
	// Update is called once per frame
	void Update ()
    {
        sl1.intensity = UDP.i1;
        sl2.intensity = UDP.i2;
        sl3.intensity = UDP.i3;
        sl4.intensity = UDP.i4;
        sl5.intensity = UDP.i5;
        sl6.intensity = UDP.i6;
        sl7.intensity = UDP.i7;
        sl8.intensity = UDP.i8;
    }
}
