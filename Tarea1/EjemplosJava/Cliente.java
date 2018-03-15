/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author giank
 */
public class Cliente {
    int edad, cedula;
    String nombre;
    Cliente sig;
    
    public Cliente(String nombre, int edad, int cedula)
    {
        this.nombre=nombre;
        this.edad= edad;
        this.cedula=cedula;
        this.sig=null;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public int getCedula() {
        return cedula;
    }

    public void setCedula(int cedula) {
        this.cedula = cedula;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Cliente getSig() {
        return sig;
    }

    public void setSig(Cliente sig) {
        this.sig = sig;
    }
    
}
