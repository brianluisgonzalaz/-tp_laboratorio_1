void menu (eEmployee listaDeEmpleados[], int len);
void menuModificacion (eEmployee listaDeEmpleados[], int len);
int indiceLibre(eEmployee listaDeEmpleados[], int len);
int idEmpleado(eEmployee listaDeEmpleados[], int len);
int cargarEmpleado(eEmployee listaDeEmpleados[],int len);
int empleadosCargados(eEmployee listaDeEmpleados[],int len);
void mostrarUnEmpleado(eEmployee unEmpleado);
void ordenarPorSalario (eEmployee listaDeEmpleados[], int len);
float salarioAcumulado (eEmployee listaDeEmpleados[], int len);
int bajaEmpleados(eEmployee listaDeEmpleados[],int len);
char getRespuesta(char mensaje []);




int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[], char respuesta);
void getString(char mensaje[], char texto[]);
void getSexo(char mensaje[], char sexo);
int esNumero(char cadena[]);
int getCadenaNumeros(char mensaje[], char numeros[]);
int getValidarInt(char mensaje[], char mensajeError[], int masBajo, int masAlto);
int esNumeroFlotante(char cadena[]);
int getCadenaNumerosFlotantes(char mensaje[], char salida[]);
float getValidarFloat(char mensaje[], float masBajo, float masAlto);
int esCadenaSoloLetras(char cadena[]);
int getCadenaSoloLetras(char mensaje[], char salida[]);
void getValidarString (char mensaje[], char salida[], int tamCadena);
char getValidarChar(char mensaje [], char letra);
void primerLetraMayuscula(char nombre[]);
void cadenaEnMayuscula (char letras[]);
void cadenaEnMinuscula (char letras[]);
