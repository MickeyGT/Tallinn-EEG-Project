using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System;
using System.Security.Permissions;

public class UDP : MonoBehaviour
{
    Thread thread;
    bool precessData = false;
    public static int power;
    private UdpClient udp;
    private bool running = true;
    private int percentage, newPercentage;

    void Start()
    {
        InvokeRepeating("UpdatePower", 1.0f, 1.0f);
        power = 1;
        udp = new UdpClient(56789);
        thread = new Thread(new ThreadStart(ThreadMethod));
        thread.Start();
    }

    void Update()
    {
        if (precessData)
        {
            precessData = false;
            //Process received data
            Debug.Log("Received: " + power);
        }
    }

    void UpdatePower()
    {
        if (newPercentage > percentage)
            power += (newPercentage - percentage) / 5;
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
        udp.Close();
        running = false;
        KillTheThread();
        
    }

    private void ThreadMethod()
    {
        while (running)
        {
            IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);
            try
            {
                Byte[] receiveBytes = udp.Receive(ref RemoteIpEndPoint);
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