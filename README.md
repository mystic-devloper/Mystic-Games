# Mystic-Precision-Arm (MPA)

## 🌟 Overview

`Mystic-Precision-Arm (MPA)` is a cutting-edge, multiple-precision lightweight math library meticulously crafted for ARM processors. Designed with efficiency and versatility in mind, MPA empowers developers to perform high-precision arithmetic operations on resource-constrained ARM devices, opening up a myriad of possibilities across various applications.

Whether you're working on cryptographic algorithms, scientific simulations, or embedded systems requiring enhanced numerical accuracy, MPA provides the robust and optimized mathematical foundation you need.

## ✨ Features

* **Multiple Precision Arithmetic:** Go beyond standard fixed-precision limits. MPA supports arbitrary-precision integers and floating-point numbers, allowing you to achieve the exact level of precision your application demands.
* **Lightweight Design:** Optimized for ARM architecture, MPA boasts a minimal footprint and efficient performance, making it ideal for embedded systems and other memory-sensitive environments.
* **High Performance:** Leveraging the ARM instruction set, MPA is engineered for speed, ensuring your high-precision computations are executed quickly and efficiently.
* **Versatile Applications:** Suitable for a wide range of uses, including:
    * Cryptography (e.g., RSA, ECC)
    * Scientific Computing
    * Financial Applications
    * Embedded Systems
    * Digital Signal Processing
    * Games and Graphics
* **Easy to Integrate:** Designed with developer experience in mind, MPA offers a clean and intuitive API for seamless integration into your ARM projects.

## 🚀 Getting Started

### Prerequisites

To build and use MPA, you will need:

* An ARM-compatible toolchain (e.g., GCC for ARM, Clang)
* Make (or your preferred build system)

### Building MPA

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/mystic-devloper/MPA-Mystic-Precision-Arm.git
    cd MPA-Mystic-Precision-Arm
    ```
2.  **Build the library:**
    Building library is very simple! First, configure `makefile` as per you need (i.e. choosing correct architecture, etc) and then run,
    ```bash
    make
    ```
    This will compile the library and generate the necessary artifacts, that are,
    * `libmpa64_arm9.a` for 64 bits `ARMv9-A`.
    * `libmpa64_arm8.a` for 64 bits `ARMv8-A`.
    * `libmpa32_arm7.a` for 32 bits `ARMv7-A`.
    * or, your specified artifact name.

    You can also change artifact names and compiler flags. For this customize makefile as per your need.

## 💡 Important Note
You can also enable cross-compilation for it you have to install few pakages such as,
  
  * `aarch64-linux-gnu`: This is for 64 bits ARM systems.
  * `arm-linux-gnueabihf`: This is for 32 bits ARM systems.

You have to change makefile commands too.
**Example**: Say your host machine is ARMv8-A then, for ARMv7-A add this to command too,
  ### For clang: 
  ```bash
  --target=arm-linux-gnueabihf \
  -march=armv7-a \
  --sysroot=/usr/arm-linux-gnueabihf \
  ```
  
  ### For GCC/G++:
  Instead of using,
  ```bash
  g++
  ```
  Use,
  ```bash
  arm-linux-gnueabihf-g++
  ```
  
  For compiling for ARMv9-A replace `arm-linux-gnueabihf-gcc` to `aarch64-linux-gnu`.

**A important thing to keep in mind**, you can run programs built for `ARMv8-A` on `ARMv9-A` and for some extent vice-versa. But if a program is native to `ARMv7-A` then, you can not run it on `ARMv8-A` or `ARMv9-A` machines and vice-versa.

## 🤝 Contributions
This project welcomes contributions and if you are interested feel free to contribute!

## ⚖️ LICENCE
This project is under MIT Open Source Licence. For full information read LICENCE.

## 🧑‍🤝‍🧑 Contributors
* Mystic-Devloper

  ... Waiting for more! Come on!
