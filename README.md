# TP_Maquina-de-estado
Emulación de un lazarillo electrónico
Mi propuesta es emular el funcionamiento básico de un lazarillo robótico, analiza si delante del sensor de proximidad hay algún obstáculo. De haberlo, esperara un lapso de tiempo para evaluar si el obstáculo sigue presente o ya tiene camino libre. Si el obstáculo sigue ahí entonces, analiza 90° a la derecha, si este nuevo camino esta libre avanzara en esta dirección. Pero, si no esta libre girara 180° pasando por la posición incial y situandose 90° de la inicial, hacia la izquierda y realizara el análisis, de no haber obstáculo avanzará hacia la izquierda. En el caso de estar bloqueado el lado izquierdo, volvera a analizar el frente.

El diseño requerira de dos variables que emularan a los motores de las ruedas, que en el momento dela giro(para el analisis de posibilidades en el momento de deteccion de un obstaculo), uno deberagirar a mayor velocidad que el otro para poder girar a todo el aparato, en el caso del avanze derecholo haran los dos a la misma velocidad. Luego estara el sensor de proximidad que estara constantementeregistrando si a cierta distancia(la distancia estara definida en el archivo de configuracion)aparece un nuevo obstaculo o no.

Todo este analisis se hace si y solo si el lazarillo esta dentro del rango de distancia permitido, que son 40Cm de distancia con la persona.
