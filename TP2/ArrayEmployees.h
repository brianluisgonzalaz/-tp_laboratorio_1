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
 * \return int devuelve -1 si hubo un error 0 si no hay memoria, 1 si se cargo con exito 2 si se cancelo la operacion
 *
 */
int addEmployee(eEmployee listaDeEmpleados[], int len);
/** \brief
 *
 * \param listaDeEmpleados[] eEmployee
 * \param len int
 * \return int
 *
 */
int findEmployeeById(eEmployee listaDeEmpleados[], int len);
int removeEmployee(eEmployee listaDeEmpleados[], int len, int id);
int sortEmployees(eEmployee listaDeEmpleados[], int len, int order);
void printEmployees(eEmployee listaDeEmpleados[], int length);
