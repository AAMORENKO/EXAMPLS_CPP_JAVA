--------------- Приклади читання/запис файлів

import java.io.*;
 
public class Program {
 
    public static void main(String[] args) {
        
        try(FileWriter writer = new FileWriter("notes3.txt", false))
        {
           // запись всей строки
            String text = "Hello Gold!";
            writer.write(text);
            // запись по символам
            writer.append('\n');
            writer.append('E');
             
            writer.flush();
        }
        catch(IOException ex){
             
            System.out.println(ex.getMessage());
        } 
    } 
}


------------------------------------------------------------------------

import java.io.*;
 
public class Program {
 
    public static void main(String[] args) {
        
        try(FileReader reader = new FileReader("notes3.txt"))
        {
           // читаем посимвольно
            int c;
            while((c=reader.read())!=-1){
                 
                System.out.print((char)c);
            } 
        }
        catch(IOException ex){
             
            System.out.println(ex.getMessage());
        }   
    } 
}

------------------------------------------------------------------------


import java.io.*;
import java.util.Arrays;
 
public class Program {
  
    public static void main(String[] args) {
          
        try(FileReader reader = new FileReader("notes3.txt"))
        {
            char[] buf = new char[256];
            int c;
            while((c = reader.read(buf))>0){
                 
                if(c < 256){
                    buf = Arrays.copyOf(buf, c);
                }
                System.out.print(buf);
            } 
        }
        catch(IOException ex){
             
            System.out.println(ex.getMessage());
        }       
    }     
}


------------------------------------------------------------------------

import java.io.*;
public class Test {

   public static void main(String args[])throws IOException {
      File file = new File("Example.txt");
      
      // Создание файла
      file.createNewFile();
      
      // Создание объекта FileWriter
      FileWriter writer = new FileWriter(file); 
      
      // Запись содержимого в файл
      writer.write("Это простой пример,\n в котором мы осуществляем\n с помощью языка Java\n запись в файл\n и чтение из файла\n"); 
      writer.flush();
      writer.close();

      // Создание объекта FileReader
      FileReader fr = new FileReader(file); 
      char [] a = new char[200];   // Количество символов, которое будем считывать
      fr.read(a);   // Чтение содержимого в массив
      
      for(char c : a)
         System.out.print(c);   // Вывод символов один за другими
      fr.close();
   }
}


------------------------------------------------------------------------

import java.io.*;

public class Test {

    public static void main(String[] args) throws Exception {
        int k1 = 2;
        int k2 = 9;
        newFile( k1, k2);
    }


    public static void newFile(int k1, int k2) throws Exception {
        FileWriter nFile = new FileWriter("file1.txt");

            for(int i = k1; i <= k2; i++) {

                    nFile.write(i);

                }

        nFile.close();
    }
}


------------------------------------------------------------------------

import java.io.FileWriter;

public class Test {

    public static void main(String[] args) throws Exception {

        FileWriter nFile = new FileWriter("file1.txt");

            nFile.write("Хокку \nПодобен лучу самурайский клинок \nИ тот затупился \nПроклятая килька в томате!!");

        nFile.close();
    }
}


------------------------------------------------------------------------

import java.io.*;

public class Test {

    public static void main(String[] args) throws Exception {
        int k1 = 2;
        int k2 = 9;
        newFile( k1, k2);
    }


    public static void newFile(int k1, int k2) throws Exception {
        FileWriter nFile = new FileWriter("file1.txt");

            for(int i = k1; i <= k2; i++) {

                    nFile.write(i+"\n");

                }

        nFile.close();
    }
}


------------------------------------------------------------------------

import java.io.FileReader;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws Exception {

        FileReader fr= new FileReader("file1.txt");
        Scanner scan = new Scanner(fr);

        fr.close();

    }
}


------------------------------------------------------------------------


import java.io.FileReader;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws Exception {

        FileReader fr= new FileReader("file1.txt");
        Scanner scan = new Scanner(fr);
            
        int i = 1;
        
        while (scan.hasNextLine()) {
            System.out.println(i + " : " + scan.nextLine());
            i++;
        }

        fr.close();


    }
}



------------------------------------------------------------------------


import java.io.*;

class Test {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter( "sample1.txt" );
        fw.close();

        FileReader fr = new FileReader( "sample2.txt" );
        fr.close();

    }
}


---------------------------------------------------------------------
#include <iostream>

// додаткова бібліотека 
#include <time.h>

using namespace std;

int main()
{
	// генератор випадкових чисел
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// розміри матрицi
	int A[100][100];
	int n, k, i;
	char z;

	n = 17;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10||abs(A[k][i])>99);
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}
		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}


--------------------------------------------------------------------------------------

#define PI 3.1415926535897932384626433832795

afx_msg void Circl(int X, int Y, int D, int WDT, COLORREF CF);

private:

	COLORREF cf, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;

--------------------------------------------------------------------------------------

#include <time.h>

using namespace std;

srand((unsigned) time (NULL));

--------------------------------------------------------------------------------------

		CClientDC dc(this);
		GetClientRect(&rc);

		hNew=CreateFont(28,0,0,0,FW_NORMAL,0,0,0,
		ANSI_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_DONTCARE,
		L"Times New Roman Cyr"); 
		hold=(HFONT)SelectObject(dc,hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH/2;
		cy = RW/2;
	
		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


// TODO


		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);		
		hold=(HFONT)SelectObject(dc,hbk);

--------------------------------------------------------------------------------------

afx_msg void Circl(int X, int Y, int D, int WDT, COLORREF CF)
{
	CClientDC dc(this);
	
	hPenOxy = CreatePen(PS_SOLID, WDT, CF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		//dc.SetPixel(xf+X, yf+Y, cf);
		dc.LineTo(xf + X, yf + Y);
		f += 0.09;
	} while (f <= 360);
}


--------------------------------------------------------------------------------------
import GrLibrary.GrLibrary;

import java.awt.*;

public class NameProject {

    public static void main(String[] args) {
        new GrLibrary();
    }
}


--------------------------------------------------------------------------GrLibrary----------

package GrLibrary;

import java.awt.*;
import java.awt.event.*;

public class GrLibrary extends Frame implements WindowListener {

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


        // TO DO


    }

    public GrLibrary() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}