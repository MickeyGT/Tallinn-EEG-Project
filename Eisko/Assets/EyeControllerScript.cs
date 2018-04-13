using UnityEngine;
using System.Collections;
using Tobii.Gaming;

public class EyeControllerScript : MonoBehaviour
{
    private static GameObject leftEye, rightEye;

    void Start ()
    {
        leftEye = GameObject.Find ("eye_L_jnt_Off");
        rightEye = GameObject.Find("eye_R_jnt_Off");
    }
	
	void Update ()
    {
        GazePoint gazePoint = TobiiAPI.GetGazePoint();
        if (gazePoint.IsValid)
        {
            Vector2 gazePosition = gazePoint.Screen;
            Vector2 roundedSampleInput = new Vector2(Mathf.RoundToInt(gazePosition.x), Mathf.RoundToInt(gazePosition.y));
            // Rotating the two eyes based on the data we get from Tobii eye tracking SDK.
            leftEye.transform.rotation = Quaternion.Euler((roundedSampleInput.y - 540) / 540 * -30, (roundedSampleInput.x - 960) / 960 * -35, 0);
            rightEye.transform.rotation = Quaternion.Euler((roundedSampleInput.y - 540) / 540 * -30, (roundedSampleInput.x - 960) / 960 * -35, 0);
        }
    }
}
