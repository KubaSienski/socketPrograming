import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("127.0.0.1", 8080);
             DataInputStream in = new DataInputStream(socket.getInputStream());
             DataOutputStream out = new DataOutputStream(socket.getOutputStream())) {

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter an integer: ");
            int number = Integer.parseInt(reader.readLine());

            out.writeInt(number); // Send the number
            int result = in.readInt(); // Receive the squared result
            System.out.println("Squared result from server: " + result);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
