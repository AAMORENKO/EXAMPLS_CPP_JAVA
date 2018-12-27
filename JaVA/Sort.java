import java.io.*;
import java.util.*;


/**
 * Created by Admin on 24.12.2018.
 */
public class Sort {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        List<String> lines = new ArrayList<String>();
        String line;
        while ((line = reader.readLine()) != null) {
            lines.add(line);
        }
        reader.close();

        String[] array=lines.toArray(new String[lines.size()]);
        Arrays.sort(array);
        for (String s : array) {
            System.out.println(s);
            }
        }
    }

