/**
	******************************************************************************
	* @file    Project/Toutorial/main.c
	* @author  Geunhyeok Lee
	* @version V0.0.1
	* @date    26-January-2022
	* @brief   Main program header
	******************************************************************************
	*/

#define u32_t unsigned int

int main()
{
	*(u32_t*)0x40023830 = *(u32_t*)0x40023830 | 0x00000009;
	*(u32_t*)0x40020C00 = *(u32_t*)0x40020C00 | 0x55000000;
	*(u32_t*)0x40020C08 = *(u32_t*)0x40020C08 | 0xff000000;
	*(u32_t*)0x40020C0C = *(u32_t*)0x40020C0C | 0xAA000000;
	*(u32_t*)0x40020C14 = *(u32_t*)0x40020C14 | 0x0000F000;

		
	while(1)
		;
	
  return 0;
}
/******************************** END OF FILE *********************************/