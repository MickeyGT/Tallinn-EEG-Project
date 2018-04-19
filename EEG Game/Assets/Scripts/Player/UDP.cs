using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System;
using System.Security.Permissions;
using UnityEngine.UI;

public class UDP : MonoBehaviour
{
    Thread thread;
    bool precessData = false;
    public static int power;
    public static int sensitivity;
    public static Boolean alphaThetaSwitch;
    private UdpClient udpHighAlph,udpAlphThet;
    private bool running = true;
    private int percentage, newPercentage;
    public Toggle alphaThetaToggle;

    void Start()
    {
        InvokeRepeating("UpdatePower", 1.0f, 1.0f);
        power = 1;
        alphaThetaSwitch = true;
        alphaThetaToggle.onValueChanged.AddListener(delegate { ToggleValueChanged(alphaThetaToggle); });
        sensitivity = 10;
        udpHighAlph = new UdpClient(25000);
        udpAlphThet = new UdpClient(26000);
        thread = new Thread(new ThreadStart(ThreadMethod));
        thread.Start();
    }

    void ToggleValueChanged(Toggle change)
    {
        Debug.Log("Toggle changed, now is" + alphaThetaToggle.isOn);
        alphaThetaSwitch = alphaThetaToggle.isOn;
    }

    void Update()
    {
        if (precessData)
        {
            precessData = false;
            //Process received data
            Debug.Log("Received: " + power + "switch Active:" + alphaThetaSwitch);
        }
    }

    void UpdatePower()
    {
        if (newPercentage >= percentage+sensitivity)
            power += (newPercentage - percentage) / sensitivity;
        else
            if(power>0)
                power--;
        percentage = newPercentage;
    }


    [SecurityPermissionAttribute(SecurityAction.Demand, ControlThread = true)]
    private void KillTheThread()
    {
        thread.Abort();
    }

    void OnApplicationQuit()
    {
        udpHighAlph.Close();
        udpAlphThet.Close();
        running = false;
        KillTheThread();
        
    }

    private void ThreadMethod()
    {
        while (running)
        {
            if (alphaThetaSwitch)
            {
                IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);
                try
                {
                    Byte[] receiveBytes = udpAlphThet.Receive(ref RemoteIpEndPoint);
                    newPercentage = Int32.Parse(Encoding.ASCII.GetString(receiveBytes));
                    Debug.Log(percentage);
                    //Done, notify the Update function
                    precessData = true;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.ToString());
                }
            }
            else
            {
                IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);
                try
                {
                    Byte[] receiveBytes = udpHighAlph.Receive(ref RemoteIpEndPoint);
                    newPercentage = Int32.Parse(Encoding.ASCII.GetString(receiveBytes));
                    Debug.Log(percentage);
                    //Done, notify the Update function
                    precessData = true;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.ToString());
                }
            }
        }
    }
}