OUTPUT_ARCH( "riscv" )
ENTRY( _start )

SECTIONS
{
  . = 0x00000000;
  .text : {
    *(.text.start)
    *(.text)
  }
  
  . = ALIGN(8);
  .data : { *(.data) }
  .bss  : { *(.bss) }

  /* Set stack top at 4KB offset */
  _stack_top = 0x1000;
}