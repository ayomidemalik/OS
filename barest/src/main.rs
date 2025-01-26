#![no_std]
#![no_main]

// fn main() {
//     println!("Hello, world!");
// }

#[unsafe(no_mangle)]
pub extern "C" fn _start() -> ! {
    let framebuffer = 0xb8000 as *mut u8;
    let (width, height) = (80, 25); // Screen dimensions
    let mut cursor_x = 0;
    let mut cursor_y = 0;

    fn write_char(framebuffer: *mut u8, x: usize, y: usize, byte: u8) {
        let offset = (y * 80 + x) * 2; // Calculate offset for 80 columns
        unsafe {
            *framebuffer.offset(offset as isize) = byte;
            *framebuffer.offset(offset as isize + 1) = 0xb; // Attribute byte
        }
    }

    for &byte in HELLO.iter() {
        if cursor_x >= width {
            cursor_x = 0; // Wrap to next line
            cursor_y += 1;
        }
        if cursor_y >= height {
            // Handle overflow: scroll up (not implemented here)
            cursor_y = height - 1; // Keep cursor within bounds
        }
        write_char(framebuffer, cursor_x, cursor_y, byte);
        cursor_x += 1; // Move cursor to the right
    }
    loop {}
}

#[panic_handler]
fn panic(_info:&core::panic::PanicInfo) -> !{
    loop {}
}

static HELLO: &[u8] = b"Hello World!";
// panic - when an error is encountered and causes program to stop executing - logical errors, causes program to abort, when it aborts, it has to unwind
// when you unwind, you're cleaning your call stack - call stack contains all called things in the error. 
// why do we have panics and errors?
