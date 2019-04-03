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


        BufferedImage imgk00, imgsm01, imgsm02, imgsm03, imgsm04, imgsm05;

        imgk00 = null;
        imgsm01 = null;
        imgsm02 = null;
        imgsm03 = null;
        imgsm04 = null;
        imgsm05 = null;
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
            ;
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        //TO DO draw

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

        }

        if(toch!=null)
        {
            x = toch.x;
            y = toch.y;

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
            toch = e.getPoint();
            mouseMoveEvent = "mouse move= " + x + "; " + y;
            //repaint();
        }

        @Override
        public void mouseClicked(MouseEvent e) {
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
        setSize(990,400);
        this.setResizable(false);
        // TO DO init
        Image icon=new ImageIcon("res/STEAmProject.png").getImage();
        this.setIconImage(icon);

        show();
    }
}
