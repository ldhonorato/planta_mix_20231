void run_teste_sensores(int execution_time)
{
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  bool sensor_metade_valor = ler_sensor_nivel(SENSOR_NIVEL_METADE);
  bool sensor_vazio_valor = ler_sensor_nivel(SENSOR_NIVEL_VAZIO);
  while ((endtime - starttime) <=execution_time)
  {
    if( ler_sensor_nivel(SENSOR_NIVEL_METADE) != sensor_metade_valor)
    {
      Serial.println("SENSOR_NIVEL_METADE:");
      sensor_metade_valor = !sensor_metade_valor;    
    }
    if( ler_sensor_nivel(SENSOR_NIVEL_VAZIO) != sensor_vazio_valor)
    {
      Serial.println("SENSOR_NIVEL_VAZIO:");
      sensor_vazio_valor = !sensor_vazio_valor;    
    }
    endtime = millis();
  }
}

void run_teste()
{
  Serial.println("Iniciando teste de sensores");
  run_teste_sensores(5000);
      
  Serial.println("Iniciando teste bomba 1 - Ligando por 5 segundos");
  ligar_bomba(BOMBA_1);
  delay(5000);
  desligar_bomba(BOMBA_1);
  
  Serial.println("Iniciando teste bomba 2 - Ligando por 5 segundos");
  ligar_bomba(BOMBA_2);
  delay(5000);
  desligar_bomba(BOMBA_2);

  Serial.println("Iniciando teste MIX");
  ligar_misturador();
  delay(5000);
  desligar_misturador();

  Serial.println("Iniciando teste Valvula");
  ligar_valvula();
  delay(5000);
  desligar_valvula();
      
  
  

}

