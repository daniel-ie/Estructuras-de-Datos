void leer(){
	    archivo.open("file.txt",ios::in);
		if(archivo.fail()){
			exit(1);
		}
	
	    if(archivo.is_open()){
	        string linea;
	        while(getline(archivo,linea)){
	        }
	        archivo.close();
	    }
