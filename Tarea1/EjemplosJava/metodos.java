public class Metodos {
    Cliente inicio, fin, mover;
    public Cliente getInicio(){
        return inicio;
    }
    public Cliente setInicio(Cliente inicio){
        this.inicio=inicio;
        return null;
    }

    public Cliente getFin() {
        return fin;
    }

    public void setFin(Cliente fin) {
        this.fin = fin;
    }

    public Cliente getMover() {
        return mover;
    }

    public void setMover(Cliente mover) {
        this.mover = mover;
    }
    public boolean insertarInicio(String nombre, int edad, int cedula){
        Cliente nuevo= new Cliente(nombre, edad, cedula);
        if(inicio==null){
            inicio= fin= nuevo;
            return true;
        }
        if(buscar(cedula)==null){
            inicio.ant= nuevo;
            nuevo.sig=inicio;
            inicio= nuevo;
            return true;
        }
        return false;
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
    public boolean eliminar(int cedula){
        Cliente aux= buscar(cedula);
        if(aux!= null){
            if(inicio==aux){
                inicio=inicio.sig;
                if(inicio.ant!=null){
                    inicio.ant= null;
                    return true;
                }
            }
            if(fin == aux){
                fin= fin.ant;
                fin.sig=null;
                return true;
            }
            aux.ant.sig= aux.sig;
            aux.sig.ant= aux.ant;
            return true;
        }
        return false;
    }

       
}
