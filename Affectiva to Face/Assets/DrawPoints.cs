using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine;
using System.Collections;
using Tobii.Gaming;
using Affdex;

public class DrawPoints : MonoBehaviour
{
    Transform mainCamera;
    CameraInput cameraInput;
    string cameraName = "USB 2.0 Webcam Device";
    string currentCameraName = "";
    public static GameObject[] spheres = new GameObject[34];
    private Vector3 offset;
    private static GameObject face,leftEye,rightEye,leftPupil,rightPupil;

    private void Start()
    {
        Color32 color = new Color32(255, 187, 153,255);
        /*
        color.a = 0; 
        face = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        face.transform.localScale = new Vector3(250, 400, 1);
        face.transform.position = this.transform.position;
        face.GetComponent<Renderer>().material.color = color;
        */

        // Code that creates the objects required for the eye and for the feature points.

        leftEye = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        leftEye.transform.localScale = new Vector3(0.5f, 0.5f, 1);
        leftEye.transform.position = this.transform.position;
        leftEye.GetComponent<Renderer>().material.color = Color.black;

        rightEye = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        rightEye.transform.localScale = new Vector3(0.5f, 0.5f, 1);
        rightEye.transform.position = this.transform.position;
        rightEye.GetComponent<Renderer>().material.color = Color.black;

        rightPupil = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        rightPupil.transform.localScale = new Vector3(0.2f, 0.2f, 1);
        rightPupil.transform.position = this.transform.position;
        rightPupil.GetComponent<Renderer>().material.color = Color.blue;

        leftPupil = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        leftPupil.transform.localScale = new Vector3(0.2f, 0.2f, 1);
        leftPupil.transform.position = this.transform.position;
        leftPupil.GetComponent<Renderer>().material.color = Color.blue;

        for (int i = 0; i <= 33; i++)
        {
            spheres[i] = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            //spheres[i].transform.localScale = new Vector3(10, 10, 1);
            spheres[i].transform.localScale = new Vector3(0.2f, 0.2f, 1);
        }
        offset = this.transform.position - spheres[11].transform.position;
    }

    // Each sphere represents one of the feature poitns. This is the function used to change their position.
    public static void changeSphere(int id, float x,float y)
    {
        spheres[id].transform.position = new Vector3(x/30, y/30, 0F);
    }

    // Function that sets the left Eye to look at X and Y coordinate on screen.
    public static void changeLeftEye(float x, float y)
    {
        leftEye.transform.position = new Vector3(x/30,y/30,+10);
        GazePoint gazePoint = TobiiAPI.GetGazePoint();
        if (gazePoint.IsValid)
        {
            Vector2 gazePosition = gazePoint.Screen;
            Vector2 roundedSampleInput = new Vector2(Mathf.RoundToInt(gazePosition.x), Mathf.RoundToInt(gazePosition.y));
            rightPupil.transform.position = new Vector3(rightEye.transform.position.x+(roundedSampleInput.x-960)/960 * -0.2f, rightEye.transform.position.y + (roundedSampleInput.y - 540) / 540 * -0.2f, 0);
        }
    }

    // Function that sets the right Eye to look at X and Y coordinate on screen.
    public static void changeRightEye(float x, float y)
    {
        rightEye.transform.position = new Vector3(x/30, y/30, +10);
        GazePoint gazePoint = TobiiAPI.GetGazePoint();
        if (gazePoint.IsValid)
        {
            Vector2 gazePosition = gazePoint.Screen;
            Vector2 roundedSampleInput = new Vector2(Mathf.RoundToInt(gazePosition.x), Mathf.RoundToInt(gazePosition.y));
            leftPupil.transform.position = new Vector3(leftEye.transform.position.x + (roundedSampleInput.x - 960) / 960 * -0.2f, leftEye.transform.position.y + (roundedSampleInput.y - 540) / 540 * -0.2f, 0);
        }
    }

    // Update is called once per frame
    void Update()
    {
        /* Code needed to select the correct webcam for affectiva SDK. Change name of the cameraName variable
        with correct webcam name or comment the code if Affectiva selects correct webcam. */
        if (currentCameraName != cameraName)
        {
            cameraInput.SelectCamera(true, cameraName);
            currentCameraName = cameraName;
        }

    }

    void LateUpdate()
    {

    }

    void Awake()
    {
        mainCamera = GameObject.FindGameObjectWithTag("MainCamera").transform;
        cameraInput = mainCamera.GetComponent<CameraInput>();
    }
}