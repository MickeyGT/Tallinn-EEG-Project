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

    void Start()
    {
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
                power = Int32.Parse(Encoding.ASCII.GetString(receiveBytes));
                Debug.Log(power);
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