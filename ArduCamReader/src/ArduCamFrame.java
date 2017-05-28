import jssc.*;
import sun.jvm.hotspot.utilities.BitMap;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

/**
 * This is a small app that can get video stream from OV2640 using a serial cable.
 */
public class ArduCamFrame extends JFrame{
    private JPanel arduCamBase;
    private JPanel arduCamPicture;
    private JComboBox serialPortSelecter;
    SerialPort serialPort;

    private Graphics graphics;
    private boolean is_header;

    private List<Byte> buffer = new ArrayList<Byte>(409600);

    public ArduCamFrame() {
        super("ArduCam Video Feeder");

        setContentPane(arduCamBase);
        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        String serialPortNames[] = SerialPortList.getPortNames();

        arduCamPicture.setVisible(false);

        for(String serialPortName : serialPortNames) {
            serialPortSelecter.addItem(serialPortName);
        }
        /*
         * TODO: gui listeners
         */
        serialPortSelecter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                serialPort = new SerialPort((String)serialPortSelecter.getSelectedItem());
                try {
                    serialPort.setParams(SerialPort.BAUDRATE_115200, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
                    serialPortSelecter.setVisible(false);
                    byte tx_data[] = new byte[2];
                    tx_data[0] = 0x10;
                    tx_data[1] = 0x0D;

                    if(serialPort.isOpened()) {
                        serialPort.writeBytes(tx_data);
                    }
                } catch (SerialPortException se) {
                    System.out.println(se);
                }
            }
        });

        /*
         * TODO: set visibility to window
         */
        setVisible(true);
    }

    private void receivedData () {
        try {
            int n = serialPort.getInputBufferBytesCount();
            byte[] buf;
            buf = serialPort.readBytes(n);
            for(int i = 0; i < n; i++) {
                buffer.add(buf[i]);
            }
        } catch (SerialPortException se) {

        }

        while (buffer.size() >= 2) {
            if((buffer.get(0) == 0xFF) && (buffer.get(1) == 0xD8) && !is_header) {
                is_header = true;
                break;
            } else if ((buffer.get(buffer.size() - 2) == 0xFF) && (buffer.get(buffer.size() - 1) == 0xD9) && is_header) {

                // updates the picture component
                arduCamPicture.update(BytesToBitmap(buffer));

                // clean the buffer
                is_header = false;
                buffer.clear();
            } else if (!is_header) {

                buffer.remove(0);
            } else {
                break;
            }
        }
    }

    private Graphics BytesToBitmap (List<Byte> buffer) {

        graphics.create(0, 0, 160, 120);

        return graphics;
    }
}
