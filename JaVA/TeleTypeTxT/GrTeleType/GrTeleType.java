package GrTeleType;

import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;


public class GrTeleType extends Frame implements WindowListener {

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
        int bx,ex,by,ey;

        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO

        int mtime=25;

        g.setColor(new Color(0,0,0));
        g.fillRect(minX,minY,maxX,maxY);

        g.setColor(new Color(255, 177, 30));
        d=600;
        x1=cx-dx*4+20;
        y1=cy-4*dy;
        x2=x1+d;
        y2=y1+d-30;
        g.drawRect(x1,y1,x2,y2);

        bx=x1+dx/2;
        ex=x2-10;
        by=y1+10;
        ey=y2-10;

        //g.drawRect(bx,by,ex,ey);
        dx=dy=45;



        //----------------------------------------------

        String z;
        String txt = "Я вивчаю мову програмування JAVA";

        String [] Stroka=new String [4];

        Stroka[0]="Найбiльше i найдорожче добро кожного народу – це його мова, та жива схованка людського духу, його багата скарбниця, в яку народ складає і своє давнє життя i своï сподiванки, розум, досвiд, почування.";
        Stroka[1]="Запашна, співуча, гнучка, милозвучна, сповнена музики і квіткових пахощів – скількома епітетами супроводяться визнання української мови.";
        Stroka[2]="Мова – втілення думки. Що багатша думка, то багатша мова. Любімо її, вивчаймо її, розвиваймо її! Борімося за красу мови, за правильність мови, за приступність мови, за багатство мови.";
        Stroka[3]="Народ, що не усвідомлює значення рідної мови для свого вищого духовного життя і сам її покидає й відрікається, виконує над собою самовбивство.";

        for (int j = 0; j <4; j++) {
            txt = Stroka[j];
            x1 = cx - 310;
            y1 = cy - 200;
            d = 18;
            dx = dy = 40;
            z = "";
            g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 25));

            int k = txt.length();
            int i = 0;
            while (y1 < ey + dy) {
                int p = 0;
                for (char ch : txt.toCharArray()) {
                    z += ch;
                    p++;
                    i++;
                    if (i > k) break;
                    if (p > 34) {
                        y1 += dy;
                        x1 = cx - 310;
                        p = 0;
                    }

                    g.setColor(new Color(255, 255, 255));
                    g.fillRect(x1, y1 - d * 2, d, d * 3);
                    g.setColor(new Color(0, 0, 0));
                    g.drawString(z, x1, y1);


                    try {
                        sleep(mtime);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                    g.setColor(new Color(0, 0, 0));
                    g.fillRect(x1, y1 - d * 2, d, d * 3);
                    g.setColor(new Color(255, 255, 255));
                    g.drawString(z, x1, y1);


                    x1 += d;
                    z = "";

                }
                y1 += dy;
                x1 = cx - 310;
            }


            try {
                sleep(mtime + 280);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if (j < 3) {
                dx = maxX / 10;
                dy = maxY / 10;
                g.setColor(new Color(0, 0, 0));
                g.fillRect(minX, minY, maxX, maxY);

                g.setColor(new Color(255, 177, 30));
                d = 600;
                x1 = cx - dx * 4 + 20;
                y1 = cy - 4 * dy;
                x2 = x1 + d;
                y2 = y1 + d - 30;
                g.drawRect(x1, y1, x2, y2);

                bx = x1 + dx / 2;
                ex = x2 - 10;
                by = y1 + 10;
                ey = y2 - 10;
            }

        }



    }

    public GrTeleType() {
        super("Друкування текстів в режимі Телетайп");
        addWindowListener(this);
        setLayout(null);
        setLocation(100,20);
        setSize(900,700);
        show();
    }
}


/*

Найбiльше i найдорожче добро кожного народу – це його мова, та жива схованка людського духу, його багата скарбниця, в яку народ складає і своє авнє життя i своï сподiванки, розум, досвiд, почування.
Запашна, співуча, гнучка, милозвучна, сповнена музики і квіткових пахощів – скількома епітетами супроводяться визнання української мови.
Мова – втілення думки. Що багатша думка, то багатша мова. Любімо її, вивчаймо її, розвиваймо її! Борімося за красу мови, за правильність мови, за приступність мови, за багатство мови.
Народ, що не усвідомлює значення рідної мови для свого вищого духовного життя і сам її покидає й відрікається, виконує над собою самовбивство.

*/