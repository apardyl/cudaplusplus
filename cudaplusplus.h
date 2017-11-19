#pragma once

#include <cuda.h>
#include <vector>
#include <list>
#include <exception>
#include <array>

namespace CudaPlusPlus {
    class CudaException : public std::exception {
    private:
        CUresult errCode;
    public:
        explicit CudaException(int cudaRes) {
            errCode = static_cast<CUresult>(cudaRes);
        }

        const char *what() const noexcept override {
            switch (errCode) {
                case CUDA_ERROR_INVALID_VALUE:
                    return "CUDA_ERROR_INVALID_VALUE";
                case CUDA_ERROR_OUT_OF_MEMORY:
                    return "CUDA_ERROR_OUT_OF_MEMORY";
                case CUDA_ERROR_NOT_INITIALIZED:
                    return "CUDA_ERROR_NOT_INITIALIZED";
                case CUDA_ERROR_DEINITIALIZED:
                    return "CUDA_ERROR_DEINITIALIZED";
                case CUDA_ERROR_PROFILER_DISABLED:
                    return "CUDA_ERROR_PROFILER_DISABLED";
                case CUDA_ERROR_PROFILER_NOT_INITIALIZED:
                    return "CUDA_ERROR_PROFILER_NOT_INITIALIZED";
                case CUDA_ERROR_PROFILER_ALREADY_STARTED:
                    return "CUDA_ERROR_PROFILER_ALREADY_STARTED";
                case CUDA_ERROR_PROFILER_ALREADY_STOPPED:
                    return "CUDA_ERROR_PROFILER_ALREADY_STOPPED";
                case CUDA_ERROR_NO_DEVICE:
                    return "CUDA_ERROR_NO_DEVICE";
                case CUDA_ERROR_INVALID_DEVICE:
                    return "CUDA_ERROR_INVALID_DEVICE";
                case CUDA_ERROR_INVALID_IMAGE:
                    return "CUDA_ERROR_INVALID_IMAGE";
                case CUDA_ERROR_INVALID_CONTEXT:
                    return "CUDA_ERROR_INVALID_CONTEXT";
                case CUDA_ERROR_CONTEXT_ALREADY_CURRENT:
                    return "CUDA_ERROR_CONTEXT_ALREADY_CURRENT";
                case CUDA_ERROR_MAP_FAILED:
                    return "CUDA_ERROR_MAP_FAILED";
                case CUDA_ERROR_UNMAP_FAILED:
                    return "CUDA_ERROR_UNMAP_FAILED";
                case CUDA_ERROR_ARRAY_IS_MAPPED:
                    return "CUDA_ERROR_ARRAY_IS_MAPPED";
                case CUDA_ERROR_ALREADY_MAPPED:
                    return "CUDA_ERROR_ALREADY_MAPPED";
                case CUDA_ERROR_NO_BINARY_FOR_GPU:
                    return "CUDA_ERROR_NO_BINARY_FOR_GPU";
                case CUDA_ERROR_ALREADY_ACQUIRED:
                    return "CUDA_ERROR_ALREADY_ACQUIRED";
                case CUDA_ERROR_NOT_MAPPED:
                    return "CUDA_ERROR_NOT_MAPPED";
                case CUDA_ERROR_NOT_MAPPED_AS_ARRAY:
                    return "CUDA_ERROR_NOT_MAPPED_AS_ARRAY";
                case CUDA_ERROR_NOT_MAPPED_AS_POINTER:
                    return "CUDA_ERROR_NOT_MAPPED_AS_POINTER";
                case CUDA_ERROR_ECC_UNCORRECTABLE:
                    return "CUDA_ERROR_ECC_UNCORRECTABLE";
                case CUDA_ERROR_UNSUPPORTED_LIMIT:
                    return "CUDA_ERROR_UNSUPPORTED_LIMIT";
                case CUDA_ERROR_CONTEXT_ALREADY_IN_USE:
                    return "CUDA_ERROR_CONTEXT_ALREADY_IN_USE";
                case CUDA_ERROR_PEER_ACCESS_UNSUPPORTED:
                    return "CUDA_ERROR_PEER_ACCESS_UNSUPPORTED";
                case CUDA_ERROR_INVALID_PTX:
                    return "CUDA_ERROR_INVALID_PTX";
                case CUDA_ERROR_INVALID_GRAPHICS_CONTEXT:
                    return "CUDA_ERROR_INVALID_GRAPHICS_CONTEXT";
                case CUDA_ERROR_NVLINK_UNCORRECTABLE:
                    return "CUDA_ERROR_NVLINK_UNCORRECTABLE";
                case CUDA_ERROR_INVALID_SOURCE:
                    return "CUDA_ERROR_INVALID_SOURCE";
                case CUDA_ERROR_FILE_NOT_FOUND:
                    return "CUDA_ERROR_FILE_NOT_FOUND";
                case CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND:
                    return "CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND";
                case CUDA_ERROR_SHARED_OBJECT_INIT_FAILED:
                    return "CUDA_ERROR_SHARED_OBJECT_INIT_FAILED";
                case CUDA_ERROR_OPERATING_SYSTEM:
                    return "CUDA_ERROR_OPERATING_SYSTEM";
                case CUDA_ERROR_INVALID_HANDLE:
                    return "CUDA_ERROR_INVALID_HANDLE";
                case CUDA_ERROR_NOT_FOUND:
                    return "CUDA_ERROR_NOT_FOUND";
                case CUDA_ERROR_NOT_READY:
                    return "CUDA_ERROR_NOT_READY";
                case CUDA_ERROR_ILLEGAL_ADDRESS:
                    return "CUDA_ERROR_ILLEGAL_ADDRESS";
                case CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES:
                    return "CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES";
                case CUDA_ERROR_LAUNCH_TIMEOUT:
                    return "CUDA_ERROR_LAUNCH_TIMEOUT";
                case CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING:
                    return "CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING";
                case CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED:
                    return "CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED";
                case CUDA_ERROR_PEER_ACCESS_NOT_ENABLED:
                    return "CUDA_ERROR_PEER_ACCESS_NOT_ENABLED";
                case CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE:
                    return "CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE";
                case CUDA_ERROR_CONTEXT_IS_DESTROYED:
                    return "CUDA_ERROR_CONTEXT_IS_DESTROYED";
                case CUDA_ERROR_ASSERT:
                    return "CUDA_ERROR_ASSERT";
                case CUDA_ERROR_TOO_MANY_PEERS:
                    return "CUDA_ERROR_TOO_MANY_PEERS";
                case CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED:
                    return "CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED";
                case CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED:
                    return "CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED";
                case CUDA_ERROR_HARDWARE_STACK_ERROR:
                    return "CUDA_ERROR_HARDWARE_STACK_ERROR";
                case CUDA_ERROR_ILLEGAL_INSTRUCTION:
                    return "CUDA_ERROR_ILLEGAL_INSTRUCTION";
                case CUDA_ERROR_MISALIGNED_ADDRESS:
                    return "CUDA_ERROR_MISALIGNED_ADDRESS";
                case CUDA_ERROR_INVALID_ADDRESS_SPACE:
                    return "CUDA_ERROR_INVALID_ADDRESS_SPACE";
                case CUDA_ERROR_INVALID_PC:
                    return "CUDA_ERROR_INVALID_PC";
                case CUDA_ERROR_LAUNCH_FAILED:
                    return "CUDA_ERROR_LAUNCH_FAILED";
                case CUDA_ERROR_NOT_PERMITTED:
                    return "CUDA_ERROR_NOT_PERMITTED";
                case CUDA_ERROR_NOT_SUPPORTED:
                    return "CUDA_ERROR_NOT_SUPPORTED";
                default:
                    return "CUDA_ERROR_UNKNOWN";
            }
        }

        static void tryCuda(CUresult res) {
            if (res == 0) return;
            else throw CudaException(res);
        }
    };

    class CudaDriver;

    class CudaDevice;

    class CudaModule;

    class CudaKernel;

    class CudaContext;

    class CudaMemory {
    public:
        virtual void *getRaw() = 0;
    };

    template<typename T>
    class CudaDeviceMemory : public CudaMemory {
        CUdeviceptr ptr = 0;
        int sizee = 0;

        explicit CudaDeviceMemory(int size) {
            CudaException::tryCuda(cuMemAlloc(&ptr, size * sizeof(T)));
            sizee = size;
        }

    public:
        void *getRaw() override {
            return &ptr;
        }

        T *copyDeviceHost() {
            auto *out = new T[sizee];
            CudaException::tryCuda(cuMemcpyDtoH(out, ptr, sizee * sizeof(T)));
            return out;
        }

        T *copyDeviceHost(int size) {
            if (size > sizee) {
                size = sizee;
            }
            auto *out = new T[size];
            CudaException::tryCuda(cuMemcpyDtoH(out, ptr, size * sizeof(T)));
            return out;
        }

        void copyHostDevice(T *input) {
            CudaException::tryCuda(cuMemcpyHtoD(ptr, input, sizee * sizeof(T)));
        }

        void copyHostDevice(T *input, int size) {
            if (size > sizee) {
                size = sizee;
            }
            CudaException::tryCuda(cuMemcpyHtoD(ptr, input, size * sizeof(T)));
        }

        friend class CudaContext;
    };

    template<typename T>
    class CudaHostMemory : public CudaMemory {
        T *ptr;

        explicit CudaHostMemory(int size) {
            CudaException::tryCuda(cuMemAllocHost((void **) &ptr, size * sizeof(T)));
        }

    public:
        void *getRaw() override {
            return &ptr;
        }

        T *data() {
            return ptr;
        }

        friend class CudaContext;
    };

    class CudaContext {
    private:
        CUcontext context = nullptr;
        bool preserve = false;

        CudaContext() = default;

        explicit CudaContext(CUdevice device, unsigned flags) {
            CudaException::tryCuda(cuCtxCreate(&context, flags, device));
        }

    public:
        template<typename T>
        CudaDeviceMemory<T> allocDevice(int size) {
            return CudaDeviceMemory<T>(size);
        }

        template<typename T>
        CudaDeviceMemory<T> allocDevice(T *data, int size) {
            CudaDeviceMemory<T> mem(size);
            mem.copyHostDevice(data);
        }

        template<typename T>
        CudaHostMemory<T> allocHost(int size) {
            return CudaHostMemory<T>(size);
        }

        void synchronize() {
            CudaException::tryCuda(cuCtxSynchronize());
        }

        ~CudaContext() {
            if (!preserve) {
                CudaException::tryCuda(cuCtxDestroy(context));
            }
        }

        void setPreserve(bool val) {
            preserve = val;
        }

        static CudaContext getExistingContext() {
            return {};
        }

        friend class CudaDevice;
    };


    class CudaDevice {
    private:
        CUdevice device = 0;

        explicit CudaDevice(int num) {
            CudaException::tryCuda(cuDeviceGet(&device, num));
        }

    public:
        CudaContext createContext(unsigned flags = 0) {
            return CudaContext(device, flags);
        }

        friend class CudaDriver;
    };

    class CudaDriver {
    private:
        CudaDriver() = default;

    public:
        CudaDevice getDevice(int deviceNumber = 0) {
            return CudaDevice(deviceNumber);
        }

        static CudaDriver getInstance() {
            static bool isInitialized;
            if (!isInitialized) {
                CudaException::tryCuda(cuInit(0));
                isInitialized = true;
            }
            return {};
        }

        static CudaDriver getExistingInstance() {
            return {};
        }
    };

    typedef std::array<unsigned, 3> CudaDimensions;

//    class CudaKernelArgs {
//    private:
//        void **arg = nullptr;
//    public:
//        ~CudaKernelArgs() {
//            delete arg;
//        }
//
//        CudaKernelArgs(std::list<CudaMemory&> args) {
//            arg = new void *[args.size()];
//            int i = 0;
//            for (auto &a : args) {
//                arg[i++] = a.getRaw();
//            }
//        }
//
//        explicit CudaKernelArgs(void **args) {
//            arg = args;
//        }
//
//        friend class CudaKernel;
//    };

    struct CudaKernelExtraArgs {
        unsigned sharedBytes = 0;
        CUstream hStream = nullptr;
        void **extra = nullptr;

        static CudaKernelExtraArgs getDefaultInstance() {
            return {};
        };
    };

    class CudaKernel {
    private:
        CUfunction kernel = nullptr;

        CudaKernel(const char *name, CUmodule module) {
            CudaException::tryCuda(cuModuleGetFunction(&kernel, module, name));
        }

    public:
        void launch(CudaDimensions grid, CudaDimensions block, void **args,
                    CudaKernelExtraArgs extraArgs = CudaKernelExtraArgs::getDefaultInstance()) {
            CudaException::tryCuda(
                    cuLaunchKernel(kernel, grid[0], grid[1], grid[2], block[0], block[1], block[2],
                                   extraArgs.sharedBytes,
                                   extraArgs.hStream, args, extraArgs.extra));
        }

        friend class CudaModule;
    };

    class CudaModule {
    private:
        CUmodule module = nullptr;

        explicit CudaModule(const char *name) {
            CudaException::tryCuda(cuModuleLoad(&module, name));
        }

    public:
        static CudaModule load(const char *modulePath) {
            return CudaModule(modulePath);
        }

        CudaKernel getKernel(const char *name) {
            return {name, module};
        }
    };
}