#define T 1000
#define TRUE 0
#define FALSE 1



typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

/** \brief Coloca todas las posiciones del array en TRUE
 *
 * \param listaDeEmpleados[] eEmployee le paso el array de empleados
 * \param len int le paso el tamaño del array
 * \return int devuelve 0 si la posicion esta en TRUE o -1 si hubo un error
 *
 */
int initEmployees(eEmployee listaDeEmpleados[], int len);
/** \brief carga los datos del empleado
 *
 * \param listaDeEmpleados[] eEmployee le paso el array de empleados
 * \param len int le paso el tamaño del array
 * \param id int le paso el id del empleado
 * \param name[] char le paso el nombre del empleado
 * \param lastName[] char le paso el apellido del empleado
 * \param salary float le paso el salario del empleado
 * \param sector int le paso el sector del empleado
 * \return int devuelve -1 si hubo un error o la posicion del empleado en el array
 *
 */
int addEmployee(eEmployee listaDeEmpleados[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(eEmployee listaDeEmpleados[], int len);
int removeEmployee(eEmployee listaDeEmpleados[], int len, int id);
int sortEmployees(eEmployee listaDeEmpleados[], int len, int order);
void printEmployees(eEmployee listaDeEmpleados[], int length);
