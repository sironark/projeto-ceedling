#include "src/tempSensor.h"
#include "build/test/mocks/mock_i2c.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_MaxValue(void){

    uint8_t tempRegisterAddress = 0x03;

    float expectedTemperature = 104.6f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(21, tempRegisterAddress, 0x3ff);







    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(26));

}



void test_MinValue(void){

    uint8_t tempRegisterAddress = 0x03;

    float expectedTemperature = -100.0f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(35, tempRegisterAddress, 0x0);







    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(40));

}
