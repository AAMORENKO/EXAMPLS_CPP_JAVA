package GrLibTraine;

import java.awt.*;
import java.awt.event.*;

public class GrLibTraine extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e) {};

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) {};
    public void windowIconified(WindowEvent e) {};
    public void windowDeiconified(WindowEvent e) {};
    public void windowActivated(WindowEvent e) {};
    public void windowDeactivated(WindowEvent e) {};

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;
        int x1, y1, x2, y2;
        int cr,cq,cb;
        int d;
        int cx, cy, dx, dy;
        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        g.setColor(new Color(0x8F46C8));
        String txt = "Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // TO DO
        g.setColor(new Color(0,0,0));
        wdk=1.5f;
        g2.setStroke(new BasicStroke(wdk));


        cx=RH/2;
        cy=RW/2;

        dx = cx / 8;
        dy = (int) (cy / 6.5);

        x1 = cx;
        y1 = cy-4*dy;

        for (cx = RH-dy; cx <= 1200; cx -= 20) {

            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            g.setColor(new Color(255,255,255));
            g.fillRect(minX,minY,maxX,maxY);
            g.setColor(new Color(0,0,0));
            Corpus(g, cx, cy, dx, dy);
            Wwind2(g, cx, cy, dx, dy);
            Koleso(g, cx - dx * 4, cy + 1 * dy, dx * 2, 2 * dy);
            Koleso(g, cx - dx * 1, cy + 1 * dy, dx * 2, 2 * dy);
            Koleso(g, cx + dx * 2, cy + 1 * dy, dx * 2, 2 * dy);
        }

    }




    private static void Corpus(Graphics G , int CX, int CY, int DX, int DY) {
        G.drawLine(CX + 7 * DX, CY - DY * 4,CX + 7 * DX, CY - DY * 4);
        G.drawLine(CX + 7 * DX, CY - DY * 4,CX + 1 * DX, CY - DY * 4);
        G.drawLine(CX + 1 * DX, CY - DY * 4,CX + 1 * DX, CY - DY * 2);
        G.drawLine(CX + 1 * DX, CY - DY * 2,CX - 3 * DX, CY - DY * 2);
        G.drawLine(CX - 3 * DX, CY - DY * 2,CX - 3 * DX, CY - DY * 5);
        G.drawLine(CX - 3 * DX, CY - DY * 5,CX - 4 * DX, CY - DY * 5);
        G.drawLine(CX - 4 * DX, CY - DY * 5,CX - 4 * DX, CY - DY * 2);
        G.drawLine(CX - 4 * DX, CY - DY * 2,CX - 5 * DX, CY - DY * 2);
        G.drawLine(CX - 5 * DX, CY - DY * 2,CX - 5 * DX, CY + DY * 1);
        G.drawLine(CX - 5 * DX, CY + DY * 1,CX - 6 * DX, CY + DY * 1);
        G.drawLine(CX - 6 * DX, CY + DY * 1,CX - 6 * DX, CY + DY * 2);
        G.drawLine(CX - 6 * DX, CY + DY * 2,CX + 6 * DX, CY + DY * 2);
        G.drawLine(CX + 6 * DX, CY + DY * 2,CX + 6 * DX, CY - DY * 3);
        G.drawLine(CX + 6 * DX, CY - DY * 3,CX + 7 * DX, CY - DY * 3);
        G.drawLine(CX + 7 * DX, CY - DY * 3,CX + 7 * DX, CY - DY * 4);

    }

    private static void Wwind2(Graphics G, int CX, int CY, int DX, int DY) {
        G.drawLine(CX + 2 * DX, CY - DY * 3,CX + 2 * DX,CY - DY * 3);
        G.drawLine(CX + 2 * DX, CY - DY * 3,CX + 2 * DX, CY - DY * 1);
        G.drawLine(CX + 2 * DX, CY - DY * 1,CX + 4 * DX, CY - DY * 1);
        G.drawLine(CX + 4 * DX, CY - DY * 1,CX + 4 * DX, CY - DY * 3);
        G.drawLine(CX + 4 * DX, CY - DY * 3,CX + 2 * DX, CY - DY * 3);
    }


    private static void Koleso(Graphics G, int CX, int CY, int DX, int DY) {
        G.setColor(new Color(255,255,255));
        G.fillOval(CX, CY, DX, DY);
        G.setColor(new Color(0,0,0));
        G.drawOval(CX, CY, DX, DY);
    }


    public GrLibTraine() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}