#include "cudaplusplus.h

using namespace cudaplusplus;

int *demo(int *arr, int arrLen) {
    CudaDriver driver = CudaDriver::getInstance();
    CudaContext context = driver.getDevice().createContext();
    CudaKernel kernel = driver.getModule("demo.ptx").getKernel("demo");

    CudaDeviceMemory<int> dataIn = context.allocDevice(arr, arrLen);
    CudaHostMemory<int> dataOut = context.allocHost(arrLen);

    kernel.launch({arrLen / 1024 + 1, 1, 1}, {1024, 1, 1}, {&dataIn, &dataOut});
    context.synchronize();

    context.setPreserve(true);
    return dataOut.data();
}