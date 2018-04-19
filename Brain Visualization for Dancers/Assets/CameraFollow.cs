using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    // The target object. In our case, the brain.
    public Transform target; 
    private float speedMod = 2.0f;//a speed modifier
    // The coordinates to the point where the camera looks at.
    private Vector3 point; 

    void Start()
    {
        // Get target's coordinates.
        point = target.transform.position;
        // Make the camera to look at it.
        transform.LookAt(point);
    }

    void Update()
    {
        // Makes the camera rotate around "point" coords, rotating around its Y axis, 20 degrees per second times the speed modifier
        transform.RotateAround(point, new Vector3(0.0f, 1.0f, 0.0f), 20 * Time.deltaTime * speedMod);
    }
}
