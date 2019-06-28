package model;

import java.util.ArrayList;
import java.util.Observable;

public class Information extends Observable {
    private int distance = 0;
    private float speed = 0;
    private String debut = "A";
    private String fin = "A";
    private String actuel = "AA";
    private boolean possible = false;
    private Parking parking;
    private ArrayList<Parking> parkingArrayList = new ArrayList<>();
    private Voiture voiture;
    private static final int CarHeight = 26;
    private static long time;
    private String[] segmentAutorise = {"FA","GF","IH","PI","OP"};
    private boolean donneesExiste = false;
    private String ParkingDispo = "";

    // Contient toutes les informations

    public Information() {
        this.voiture = new Voiture(this.actuel);
    }

    public boolean getDonneesExiste() {
        return this.donneesExiste;
    }

    public void setDonneesExiste(boolean donneesExiste) {
        this.donneesExiste = donneesExiste;
    }

    public void setDistance(String distance) {
        this.possible = lookIfCanPark(Integer.parseInt(distance),this.distance);
        this.distance = Integer.parseInt(distance);
        notifyObservers();
    }

    public int getDistance() {
        return distance;
    }

    public void setPathFinding(String pathFinding) {
        if (this.debut.equals(pathFinding.substring(0,1)) == false) {
            this.debut = pathFinding.substring(0,1);
            notifyObservers();
        }
        if (this.fin.equals(pathFinding.substring(1,2)) == false) {
            this.fin = pathFinding.substring(1,2);
            notifyObservers();
        }
        if (this.actuel.equals(pathFinding.substring(2,4)) == false) {
            this.actuel = pathFinding.substring(2,4);
            this.voiture = new Voiture(this.actuel);
            notifyObservers();
        }
    }

    public String getDebut() {
        return this.debut;
    }

    public String getFin() {
        return this.fin;
    }

    public String getActuel() {
        return this.actuel;
    }

    public void setSpeed(String speed) {
        this.speed = Float.valueOf(speed);
        notifyObservers();
    }

    public float getSpeed() {
        return speed;
    }

    public boolean getPossible() {
        return this.possible;
    }

    public Observable getObservable() {
        return this;
    }

    public boolean lookIfCanPark(int actualDistance, int lastDistance) {
        if (actualDistance >= lastDistance+10) {
            this.time = System.nanoTime();
        }
        else if (actualDistance < lastDistance+10) {
            this.time = System.nanoTime() - this.time;
            float length = this.time * this.speed;
            if (length >= this.CarHeight) {
                for (String segment: segmentAutorise) {
                    if (segment.equals(this.actuel) == true) {
                        this.setParking();
                        notifyObservers();
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

    public int getX() {
        return voiture.getPosX();
    }

    public int getY() {
        return voiture.getPosY();
    }

    public void animation() {
        this.voiture.animation(this.speed);
        notifyObservers();
    }

    public void setParking() {
        boolean existe = false;

        if (this.parkingArrayList.isEmpty() == false) {
            for (Parking parking : this.parkingArrayList) {
                if (this.actuel.equals(parking.getSegment())) {
                    existe = true;
                    break;
                } else {
                    existe = false;
                }
            }
        }
        if (existe == false) {
            this.parking = new Parking(this.actuel);
            this.parkingArrayList.add(this.parking);
            this.ParkingDispo = this.ParkingDispo + " " + this.parking.getSegment();
        } else
            return;
    }
    
    public Parking getParking() {
        return this.parking;
    }

    public String getParkingDispo() {
        return this.ParkingDispo;
    }
}
