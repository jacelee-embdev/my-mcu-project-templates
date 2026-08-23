#include "sys.h"
#include "delay.h"
#include "uart.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    uart1_init(115200);
    
    while(1)
    {
        printf("TEST,1142!\r\n");
        delay_ms(1000);
    }
}
