//! main.rs
#![no_std]
#![no_main]

mod writer;
use writer::FrameBufferWriter;
use core::fmt::Write;
use bootloader_api::config::Mapping;
use x86_64::instructions::hlt;

pub static BOOTLOADER_CONFIG: bootloader_api::BootloaderConfig = {
    let mut config = bootloader_api::BootloaderConfig::new_default();
    config.mappings.physical_memory = Some(Mapping::Dynamic);
    config.kernel_stack_size = 100 * 1024; // 100 KiB
    config
};

bootloader_api::entry_point!(my_entry_point, config = &BOOTLOADER_CONFIG);

fn my_entry_point(boot_info: &'static mut bootloader_api::BootInfo) -> ! {
    let frame_buffer_info = boot_info.framebuffer.as_mut().unwrap().info();
    let buffer = boot_info.framebuffer.as_mut().unwrap().buffer_mut();
    let mut frame_buffer_writer = FrameBufferWriter::new(buffer, frame_buffer_info);

    // Test the `print!` macro
    print!(
        "Hello, world!\nThis is a test.\nBlue Text\tIndented Text",
        writer = &mut frame_buffer_writer
    );

    loop {
        hlt(); // Prevent unnecessary CPU usage
    }
}

#[macro_export]
macro_rules! print {
    ($fmt:expr, writer = $writer:expr $(, $args:expr)*) => {{
        use core::fmt::Write;
        $writer.write_fmt(format_args!($fmt $(, $args)*)).unwrap();
    }};
}

#[panic_handler]
fn panic(_info: &core::panic::PanicInfo) -> ! {
    loop {
        hlt();
    }
}
