#include "sys.h"
#include "delay.h"
#include "usart1.h"

int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    SystemClock_Config(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    usart1_init(115200);
    
    while(1)
    {
        printf("1142!\r\n");
        delay_ms(1000);
    }
}
