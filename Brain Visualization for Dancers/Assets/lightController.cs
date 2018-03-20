using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lightController : MonoBehaviour
{
    public Light sl1,sl2,sl3,sl4,sl5,sl6,sl7,sl8; // spotlights
    int i1, i2, i3, i4, i5, i6, i7, i8, ni1, ni2, ni3, ni4, ni5, ni6, ni7, ni8;

	// Use this for initialization
	void Start ()
    {
        InvokeRepeating("UpdateLights", 1.0f, 1.0f);
        Light sl1 = GetComponent("Spotlight1") as Light;
        Light sl2 = GetComponent("Spotlight2") as Light;
        Light sl3 = GetComponent("Spotlight3") as Light;
        Light sl4 = GetComponent("Spotlight4") as Light;
        Light sl5 = GetComponent("Spotlight5") as Light;
        Light sl6 = GetComponent("Spotlight6") as Light;
        Light sl7 = GetComponent("Spotlight7") as Light;
        Light sl8 = GetComponent("Spotlight8") as Light;
        sl1.intensity = 0;
        sl2.intensity = 0;
        sl3.intensity = 0;
        sl4.intensity = 0;
        sl5.intensity = 0;
        sl6.intensity = 0;
        sl7.intensity = 0;
        sl8.intensity = 0;
    }
	
	// Update is called once per frame
	void UpdateLights ()
    {
        ni1 = UDP.i1;
        ni2 = UDP.i2;
        ni3 = UDP.i3;
        ni4 = UDP.i4;
        ni5 = UDP.i5;
        ni6 = UDP.i6;
        ni7 = UDP.i7;
        ni8 = UDP.i8;

        if (ni1 > i1)
            sl1.intensity = (ni1 - i1) / 5;
        else
            if(sl1.intensity > 0)
                sl1.intensity = sl1.intensity - 1;
        if (ni2 > i2)
            sl2.intensity = (ni2 - i2) / 5;
        else
            if (sl2.intensity > 0)
                sl2.intensity = sl2.intensity - 1;
        if (ni3 > i3)
            sl3.intensity = (ni3 - i3) / 5;
        else
            if (sl3.intensity > 0)
                sl3.intensity = sl3.intensity - 1;
        if (ni4 > i4)
            sl4.intensity = (ni4 - i4) / 5;
        else
            if (sl4.intensity > 0)
                sl4.intensity = sl4.intensity - 1;
        if (ni5 > i5)
            sl5.intensity = (ni5 - i5) / 5;
        else
            if (sl5.intensity > 0)
                sl5.intensity = sl5.intensity - 1;
        if (ni6 > i6)
            sl6.intensity = (ni6 - i6) / 5;
        else
            if (sl6.intensity > 0)
                sl6.intensity = sl6.intensity - 1;
        if (ni7 > i7)
            sl7.intensity = (ni7 - i7) / 5;
        else
            if (sl7.intensity > 0)
                sl7.intensity = sl7.intensity - 1;
        if (ni8 > i8)
            sl8.intensity = (ni8 - i8) / 5;
        else
            if (sl8.intensity > 0)
                sl8.intensity = sl8.intensity - 1;

        i1 = ni1;
        i2 = ni2;
        i3 = ni3;
        i4 = ni4;
        i5 = ni5;
        i6 = ni6;
        i7 = ni7;
        i8 = ni8;
    }

    private void Update()
    {
        
    }
}
