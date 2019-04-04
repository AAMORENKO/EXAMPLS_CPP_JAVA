package GUImgLib;


import java.io.File;
import java.nio.CharBuffer;
import java.util.Arrays;
import java.util.Random;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Scanner;

import static java.lang.Thread.sleep;

public class GUWindow01 extends  Frame implements
        WindowListener, MouseMotionListener, MouseListener {

    public int x, y, w, h;
    public int x1, y1, x2, y2, x3, y3;
    public int cr, cq, cb;
    public int d;
    public int cx, cy, dx, dy;

    String mouseEvent="";
    String mouseMoveEvent="";
    String mouseDragEvent="";
    String ctrl="";

    public String ms="";

    public void windowOpened(WindowEvent e) {    }    ;

    public void windowClosing(WindowEvent e) {

        try
        {
            FileWriter writer = new FileWriter("data.txt");
            String txt = "close";
            writer.write(txt);
            writer.flush();
            writer.close();
        } catch (IOException ef) {
            ef.printStackTrace();
        }

        dispose();
        //System.exit(0);
    };

    public void windowClosed(WindowEvent e) { };
    public void windowIconified(WindowEvent e) { };
    public void windowDeiconified(WindowEvent e) { };
    public void windowActivated(WindowEvent e) { };
    public void windowDeactivated(WindowEvent e) { };
    public void mouseMoved(MouseEvent e) { };
    public void mouseClicked(MouseEvent e) { };
    public void mousePressed(MouseEvent e) { };
    public void mouseReleased(MouseEvent e) { };
    public void mouseEntered(MouseEvent e) { };
    public void mouseExited(MouseEvent e) { };
    public void mouseDragged(MouseEvent e) { };


    public Point toch=null;
    public int count=0;

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        float wdk = 3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        // TO DO init

        boolean fpic = false;
        dx = 325;
        dy = 190;
        x1 = 20;
        y1 = 70;
        x2 = x1;
        y2 = y1 - 50;
        x3 = x1 + 880;
        y3 = y1 + 600;


        BufferedImage imgk00, imgsm01, imgsm02, imgsm03, imgsm04, imgsm05,imgo06,imgyes,imgno;

        imgk00 = null;
        imgsm01 = null;
        imgsm02 = null;
        imgsm03 = null;
        imgsm04 = null;
        imgsm05 = null;
        imgo06 = null;
        imgyes = null;
        imgno = null;

        BufferedImage[] imgkw = new BufferedImage[20];
        for (int i = 1; i <= 18; i++) {
            imgkw[i] = null;
        }

        try {
            imgk00 = ImageIO.read(new File("res/k00.png"));
            imgsm01 = ImageIO.read(new File("res/sm01.png"));
            imgsm02 = ImageIO.read(new File("res/sm02.png"));
            imgsm03 = ImageIO.read(new File("res/sm03.png"));
            imgsm04 = ImageIO.read(new File("res/sm04.png"));
            imgsm05 = ImageIO.read(new File("res/sm05.png"));
            imgo06 = ImageIO.read(new File("res/OTVET.png"));
            imgyes = ImageIO.read(new File("res/button_ok.png"));
            imgno = ImageIO.read(new File("res/button_cancel.png"));
            for (int i = 1; i <= 18; i++) {
                if (i < 10) ms = "res/k0" + i + ".png";
                else ms = "res/k" + i + ".png";
                imgkw[i] = ImageIO.read(new File(ms));
            }
            fpic = true;
        } catch (IOException e) {
            e.printStackTrace();
        }

        BufferedReader br = null;
        int numb = 0;
        ms = "";
        try {
            br = new BufferedReader(new FileReader("data.txt"));
            ms = br.readLine();
            numb = Integer.parseInt(ms);
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        //TO DO draw

        int xx=280; int dxx=308;
        int yy=350; int dyy=105;

        int[] kwdX=new int[5];
        int[] kwdY=new int[5];
        boolean[] otw=new boolean[5];


        if (fpic) {

            switch (numb % 3) {
                case 1:
                    g.drawImage(imgsm01, x2, y2, null);
                    break;
                case 2:
                    g.drawImage(imgsm02, x2, y2, null);
                    break;
                case 0:
                    g.drawImage(imgsm03, x2, y2, null);
                    break;
            }

            ms="Питання за номером: "; ms+=numb;
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 24));
            g.setColor(new Color(255, 255, 202));
            g.drawString(ms,250,105);

            g.drawImage(imgkw[numb], x1, y1+80, null);

            g.drawImage(imgk00, x3, y3, null);

            int k=1;
            for (int i = 0; i <2 ; i++) {
                x1=xx;y1=yy+i*dyy;
                for (int j = 0; j <2 ; j++) {
                    g.drawImage(imgo06, x1, y1, null);
                    kwdX[k]=x1-2;kwdY[k]=y1-2;
                    x1+=dxx; k++;
                }
            }

            switch(numb)
            {
                case 1:

                    // Питання
                    x=205; y=205;
                    g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 26));
                    g.setColor(new Color(103, 4, 205));
                    ms="Як називається процес створення копії даних на носії";
                    g.drawString(ms,x,y); y+=29;
                    ms="(жорсткому диску, USB-флеш-накопичувачі і тощо), ";
                    g.drawString(ms,x,y); y+=29;
                    ms="призначеному для відновлення даних в оригінальному або";
                    g.drawString(ms,x,y); y+=29;
                    ms="новому місці їх розташування в разі їх пошкодження або ";
                    g.drawString(ms,x,y); y+=29;
                    ms="руйнування?";
                    g.drawString(ms,x,y); y+=29;

                    //Відповіді
                    g.setFont(new Font("Trebuchet Ms", Font.BOLD, 22));
                    g.setColor(new Color(205, 44, 84));
                    x=310; y=400;
                    ms="Резервне копіювання";
                    g.drawString(ms,x,y);
                    x=310; y=510;
                    ms="Електронне архіювання";
                    g.drawString(ms,x,y);
                    x=630; y=400;
                    ms="Архівація даних";
                    g.drawString(ms,x,y);
                    x=630; y=510;
                    ms="Створоення розділів";
                    g.drawString(ms,x,y);

                    otw[1]=true; otw[2]=false;
                    otw[3]=false; otw[4]=false;

                    break;


                case 2:
                    // Питання
                    x=350; y=205;
                    g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 26));
                    g.setColor(new Color(103, 4, 205));
                    ms="В який день відзначається День бекапу?";
                    g.drawString(ms,x,y);

                    //Відповіді
                    g.setFont(new Font("Trebuchet Ms", Font.BOLD, 22));
                    g.setColor(new Color(205, 44, 84));
                    x=320; y=400;
                    ms="1 квітня";
                    g.drawString(ms,x,y);
                    x=320; y=510;
                    ms="31 березня";
                    g.drawString(ms,x,y);
                    x=640; y=400;
                    ms="2 квітня";
                    g.drawString(ms,x,y);
                    x=640; y=510;
                    ms="3 травня";
                    g.drawString(ms,x,y);

                    otw[1]=false; otw[2]=false;
                    otw[3]=true; otw[4]=false;

                    break;
            }

        }

        if(toch!=null)
        {
            x = toch.x;
            y = toch.y;

            for (int p = 1; p < 5; p++) {
                if (x > kwdX[p] && x < kwdX[p]+dxx &&
                        y > kwdY[p] && y < kwdY[p]+dyy)
                {
                    g.setColor(new Color(69, 35,105));
                    g2.setStroke(new BasicStroke(5));
                    g.drawRect(kwdX[p],kwdY[p],dxx,dyy);

                    if(otw[p])
                    {
                        g.drawImage(imgyes, 90, 330, null);
                    }else
                    {
                        g.drawImage(imgno, 90, 350, null);
                    }
                }
            }

            if (x > x3 && x < x3 + 39 && y > y3 && y < y3+38)
            {
                g.setColor(new Color(18, 14, 109));
                g2.setStroke(new BasicStroke(wdk));
                g.drawRect(x3-1, y3-1, 39, 38);

                try {
                    sleep(250);
                } catch (InterruptedException et) {
                    et.printStackTrace();
                }

                try
                {
                    FileWriter writer = new FileWriter("data.txt");
                    String txt = "close";
                    writer.write(txt);
                    writer.flush();
                    writer.close();
                } catch (IOException ef) {
                    ef.printStackTrace();
                }
                dispose();

            }

        }



    }

/*
    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }
*/

    MouseAdapter mouseHandler = new MouseAdapter()
    {
        @Override
        public void mouseMoved(MouseEvent e) {
            toch=null;
            toch = e.getPoint();
            mouseMoveEvent = "mouse move= " + x + "; " + y;
            //repaint();
        }

        @Override
        public void mouseClicked(MouseEvent e) {
            toch=null;
            toch = e.getPoint();
            mouseEvent = "mouse click= " + x + "; " + y;
            repaint();
        }
    };

    public GUWindow01() {

        super("Вікно з питанням.");
        addWindowListener(this);
        addMouseListener(mouseHandler);
        addMouseMotionListener(mouseHandler);
        setLayout(null);
        setLocation(20,70);
        setSize(990,600);
        this.setResizable(false);
        // TO DO init
        Image icon=new ImageIcon("res/STEAmProject.png").getImage();
        this.setIconImage(icon);

        show();
    }
}