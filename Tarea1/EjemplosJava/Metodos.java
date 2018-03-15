/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author giank
 */
public class Metodos {
    Cliente inicio, fin;//Apunta al inicio de una lista
    public boolean insertarInicio(String nombre, int edad, int cedula){
        Cliente nuevo = new Cliente(nombre, edad, cedula);
        Cliente aux = inicio;
        if (inicio == null){
            fin = inicio = nuevo;
            return true;
        }
        Cliente encontrado= buscar(cedula);
        if (encontrado==null){
            nuevo.sig = inicio;
            inicio = nuevo;
            return true;
        }
        return false;
    }

    public Cliente getInicio() {
        return inicio;
    }

    public void setInicio(Cliente inicio) {
        this.inicio = inicio;
    }

    public Cliente getFin() {
        return fin;
    }

    public void setFin(Cliente fin) {
        this.fin = fin;
    }
    
    
    public Cliente buscar(int cedula){
        Cliente aux= inicio;
        while(aux!= null){
            if(aux.cedula== cedula){
                return aux;
            }
            aux = aux.sig;
        }
        return null;
    }
    public boolean modificar(String nombre, int edad, int cedula){
        Cliente encontrado= buscar(cedula);
        if (encontrado!= null){
            encontrado.setNombre(nombre);
            encontrado.setEdad(edad);
            return true;
        }
        return false;
    }
    
}