package model;

public class Voiture {
    public int posX;
    public int posY;
    public String actuel;
    private float speed;
    private int distancePixel;
    private int distanceReel;
    private String TableauDistanceReel[][] = {  {"AB","40"},{"AF","80"},{"AD","28"}, {"BA","40"}, {"BC","28"}, {"CB","28"},
                                                {"CD","40"},{"CK","53"},{"DC","40"}, {"DE","80"}, {"DA","28"}, {"ED","80"},
                                                {"EF","28"},{"FA","80"},{"FE","28"}, {"FG","40"}, {"GF","40"}, {"GJ","80"},
                                                {"GH","40"},{"HG","40"},{"HI","80"}, {"IH","80"}, {"IJ","40"}, {"IP","53"},
                                                {"JI","40"},{"JG","80"},{"JK","163"},{"JL","28"}, {"KC","53"}, {"KJ","163"},
                                                {"KN","53"},{"LJ","28"},{"LM","124"},{"ML","124"},{"MO","28"}, {"NK","53"},
                                                {"NO","40"},{"ON","40"},{"OP","163"},{"OM","28"}, {"PO","163"},{"PI","53"}};
    private Coordonne coordonne;
    private Coordonne[] vecteur;
    private static long time;
    private int distanceEffectue;

    public Voiture(String actuel) {
        this.actuel = actuel;
        this.distanceEffectue = 0;
        this.vecteur = new Coordonne[2];
        this.SetCoordonne(actuel.substring(0,1),0);
        this.posX = vecteur[0].getX();
        this.posY = vecteur[0].getY();
        this.SetCoordonne(actuel.substring(1,2),1);
        System.out.println(actuel.substring(0,1) + " : x1 = " + vecteur[0].getX() + " y1 = " + vecteur[0].getY() +"  "+ actuel.substring(1,2) +" : x2 = " + vecteur[1].getX() + " y2 = " + vecteur[1].getY());
        this.distancePixel = (int)Math.sqrt(Math.pow(vecteur[1].getX() - vecteur[0].getX(),2) + Math.pow(vecteur[1].getY() - vecteur[0].getY(),2));
        for (int i = 0; i < 42; i++) {
            if (this.actuel.equals(this.TableauDistanceReel[i][0])) {
                this.distanceReel = Integer.parseInt(this.TableauDistanceReel[i][1]);
                break;
            }
        }
        this.time = System.nanoTime();
    }

    public int getPosX() {
        return posX;
    }

    public int getPosY() {
        return posY;
    }

    public void SetCoordonne(String actuel, int i) {
        this.coordonne = new Coordonne(actuel);
        this.vecteur[i] = this.coordonne;
    }

    public void animation(float speed) {
        long time = (System.nanoTime() - this.time);
        if (time >= 50000000) {
            if (this.distanceEffectue >= this.distancePixel) {
                return;
            } else {
                this.speed = speed * 10;
                double temps = Math.round(time * (Math.pow(10, -8)));
                double dis = Math.round(this.distancePixel * ((double) this.speed * (temps)));
                double distance = (dis) / this.distanceReel;
                int distancePixel = (int) distance;
                this.distanceEffectue = this.distanceEffectue + distancePixel;
                if (vecteur[1].getX() - vecteur[0].getX() < 0) {
                    this.posX = this.posX - distancePixel;
                }
                if (vecteur[1].getX() - vecteur[0].getX() > 0) {
                    this.posX = this.posX + distancePixel;
                }
                if (vecteur[1].getY() - vecteur[0].getY() < 0) {
                    this.posY = this.posY - distancePixel;
                }
                if (vecteur[1].getY() - vecteur[0].getY() > 0) {
                    this.posY = this.posY + distancePixel;
                }
            }
            this.time = System.nanoTime();
        }
    }
}
