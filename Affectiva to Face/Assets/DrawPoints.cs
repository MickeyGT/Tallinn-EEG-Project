using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine;
using System.Collections;
using Affdex;

public class DrawPoints : MonoBehaviour
{
    Transform mainCamera;
    CameraInput cameraInput;
    string cameraName = "USB 2.0 Webcam Device";
    string currentCameraName = "";
    public static GameObject[] spheres = new GameObject[34];
    private Vector3 offset;

    private void Start()
    {
        for (int i = 0; i <= 33; i++)
        {
            spheres[i] = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            spheres[i].transform.localScale = new Vector3(10, 10, 1);
        }
        offset = this.transform.position - spheres[11].transform.position;
    }

    public static void changeSphere(int id, float x,float y)
    {
        spheres[id].transform.position = new Vector3(x, y, 0F);
    }

    // Update is called once per frame
    void Update()
    {

        if (currentCameraName != cameraName)
        {
            cameraInput.SelectCamera(true, cameraName);
            currentCameraName = cameraName;
        }

    }

    void LateUpdate()
    {
        // Set the position of the camera's transform to be the same as the player's, but offset by the calculated offset distance.
        this.transform.position = spheres[11].transform.position + offset;
    }

    void Awake()
    {
        mainCamera = GameObject.FindGameObjectWithTag("MainCamera").transform;
        cameraInput = mainCamera.GetComponent<CameraInput>();
    }
}