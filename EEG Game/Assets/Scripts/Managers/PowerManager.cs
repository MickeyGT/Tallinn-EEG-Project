using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PowerManager : MonoBehaviour
{
    Text text;

    void Awake ()
    {
        text = GetComponent <Text> ();
    }

    void Update ()
    {
        text.text = "Power: " + UDP.power.ToString();
    }
}
