import java.io.*;
import java.util.Scanner;

public class WriteReadFileJava {

    public static void main(String[] args) throws IOException {

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
        char [] a = new char[256];   // Количество символов, которое будем считывать
        fr.read(a);   // Чтение содержимого в массив

        for(char c : a)
            System.out.print(c);   // Вывод символов один за другими
        fr.close();


        String namefile="OS_W.txt";

        fr= new FileReader(namefile);
        Scanner scan = new Scanner(fr);

        int i = 1;
        int wd=0;

        while (scan.hasNextLine()) {
            String buff=scan.nextLine();
            if(buff.length()!=0) {
                wd++;
                for (int j = 0; j <= buff.length(); j++) {
                    if (buff.charAt(i) == ' ') {
                        wd++;
                    }
                }
            }
            System.out.println(i + " : " + buff);
            i++;
        }

      fr.close();

        String txt="Считано из файла "+namefile;
        txt+="\nСтрок: "+(i-1);
        txt+="\nСлов: "+wd;

        file = new File("C:\\TEMP\\ResSolReadFile.txt");
        file.createNewFile();
        writer = new FileWriter(file);
        writer.write(txt);
        writer.flush();
        writer.close();

    }

}
