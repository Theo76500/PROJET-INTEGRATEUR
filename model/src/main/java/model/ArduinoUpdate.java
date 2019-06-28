package model;

import com.fazecast.jSerialComm.*;
import contract.IModel;

public class ArduinoUpdate implements SerialPortMessageListener {

    private String valeur;
    private SerialPort sp;
    private IModel model;
    private String[] valeurtest;
    public boolean valeurexiste = false;

    public ArduinoUpdate(SerialPort sp, IModel model) {
        this.sp = sp;
        this.model = model;
    }

    @Override
    public byte[] getMessageDelimiter() {
        return new byte[] {(byte)0x23};
    }

    @Override
    public boolean delimiterIndicatesEndOfMessage() {
        return true;
    }

    @Override
    public int getListeningEvents() {
        return sp.LISTENING_EVENT_DATA_RECEIVED;
    }

    @Override
    public void serialEvent(SerialPortEvent event) {
        this.valeur = "";
        this.valeurtest = new String[3];
        byte[] newData = event.getReceivedData();
        for (int i = 0; i < newData.length; ++i) {
            this.valeur = this.valeur + (char) newData[i];
        }
        //System.out.println(this.valeur + " taille : "+newData.length);
        /* Mode vidéo (16,13) / Mode réel (19,16)*/
        if (newData.length > 16) return;
        if (newData.length < 13) return;
        this.valeur = this.valeur.replaceAll("#","");
        this.valeur = this.valeur.replaceAll("\r\n","");
        //this.valeur = this.valeur.substring(2);
        this.valeurtest = this.valeur.split("/");
        for (int i = 0; i < 3; i++) {
            //System.out.println("Valeur n°"+i+" = "+this.valeurtest[i]);
            switch (i) {
                case 0:
                    try {
                        Integer.parseInt(valeurtest[i]);
                    } catch (NumberFormatException e) {
                        return;
                    }
                    break;
                case 1:
                    try {
                        Float.valueOf(valeurtest[i]);
                    } catch (NumberFormatException e) {
                        return;
                    }
                    break;
                case 2:
                    if (valeurtest[i].length() != 4) {
                        return;
                    }
                    break;
                default:
                    break;
            }
        }

        if (valeurexiste == false)
            this.valeurexiste = true;
        model.action(this.valeur);
        model.animation();
    }

    public String getValeur() {
        return this.valeur;
    }

    // Ouverture du port

    public Boolean OpenPort() {
        if (sp.openPort()) {
            System.out.println("Port is open !");
            return true;
        } else {
            System.out.println("Failed to open port...");
            return false;
        }
    }

    // Fermeture du port

    public Boolean ClosePort() {
        if (sp.closePort()) {
            System.out.println("Port is closed !");
            return true;
        } else {
            System.out.println("Failed to close port...");
            return false;
        }
    }

    public boolean getValeurExiste() {
        return this.valeurexiste;
    }
}
