#pragma once

#include <cuda.h>
#include <exception>
#include <array>
#include <random>

namespace cudaplusplus {
    /*!
     * @class CudaException
     * @brief Wraps CUresult in an exception.
     */
    class CudaException : public std::exception {
    private:
        CUresult errCode;
    public:
        explicit CudaException(CUresult cudaRes) {
            errCode = cudaRes;
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

        /*!
         * Returns raw error code, that caused the exception.
         */
        const CUresult errorCode() const noexcept {
            return errCode;
        }

        /*!
         * @brief Throws CudaException if parameter is not equal to CUDA_SUCCESS
         * @param res Cuda error code
         */
        static void tryCuda(CUresult res) {
            if (res == CUDA_SUCCESS) return;
            else throw CudaException(res);
        }
    };

    class CudaDriver;

    class CudaDevice;

    class CudaModule;

    class CudaKernel;

    class CudaContext;

    /*!
     * @class CudaMemory
     * @brief Abstract class representing allocated memory
     */
    class CudaMemory {
    public:
        virtual void *getRaw() = 0;
    };

    /*!
     * @class CudaDeviceMemory
     * @brief Cuda device memory wrapper
     * @tparam T array type
     */
    template<typename T>
    class CudaDeviceMemory : public CudaMemory {
        CUdeviceptr ptr = 0;
        int size = 0;

        explicit CudaDeviceMemory(int size) {
            CudaException::tryCuda(cuMemAlloc(&ptr, size * sizeof(T)));
            this->size = size;
        }

    public:
        void *getRaw() override {
            return &ptr;
        }

        /*!
         * @brief Allocates memory on host and copies data from device to it.
         */
        T *copyDeviceHost() {
            auto *out = new T[size];
            CudaException::tryCuda(cuMemcpyDtoH(out, ptr, size * sizeof(T)));
            return out;
        }

        /*!
         * @brief Allocates memory on host and copies data from device to it.
         * @param size Size of array to alloc and number of elements to copy.
         */
        T *copyDeviceHost(int size) {
            auto *out = new T[size];
            if (size > this->size) {
                size = this->size;
            }
            CudaException::tryCuda(cuMemcpyDtoH(out, ptr, size * sizeof(T)));
            return out;
        }

        /*!
         * @brief Copies data from device to host.
         * @param out Target array, must be large enough.
         * @param size Number of elements to copy or 0 (copy all).
         */
        T *copyDeviceHost(T *out, int size = 0) {
            if (size <= 0) {
                size = this->size;
            }
            CudaException::tryCuda(cuMemcpyDtoH(out, ptr, size * sizeof(T)));
            return out;
        }

        /*!
         * @brief Copies array from host to device.
         * @param input Source array, must not be smaller than target.
         */
        void copyHostDevice(T *input) {
            CudaException::tryCuda(cuMemcpyHtoD(ptr, input, size * sizeof(T)));
        }

        /*!
         * @brief Copies array from host to device.
         * @param input Source array.
         * @param size Number of elements to copy.
         */
        void copyHostDevice(T *input, int size) {
            if (size > this->size) {
                size = this->size;
            }
            CudaException::tryCuda(cuMemcpyHtoD(ptr, input, size * sizeof(T)));
        }

        friend class CudaContext;
    };

    /*!
     * @class CudaValue
     * @brief Allows passing a single value to CudaKernel
     * @tparam T value type
     */
    template<typename T>
    class CudaValue : public CudaMemory {
        T *ptr;
    public:
        explicit CudaValue(T val) {
            ptr = new T;
            *ptr = val;
        }

        void *getRaw() override {
            return ptr;
        }

        T &operator*() {
            return ptr;
        }

        ~CudaValue() {
            delete ptr;
        }
    };

    /*!
     * @class CudaHostMemory
     * @brief Cuda host memory wrapper
     * @tparam T array type
     */
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

    /*!
     * @class CudaContext
     * @brief Cuda context, allows memory management and device synchronisation.
     */
    class CudaContext {
    private:
        CUcontext context = nullptr;
        bool preserve = false;

        CudaContext() = default;

        explicit CudaContext(CUdevice device, unsigned flags) {
            CudaException::tryCuda(cuCtxCreate(&context, flags, device));
        }

    public:
        /*!
         * @brief Allocates device memory in context.
         * @tparam T Array type
         * @param size Array size
         */
        template<typename T>
        CudaDeviceMemory<T> allocDevice(int size) {
            return CudaDeviceMemory<T>(size);
        }

        /*!
         * @brief Allocates device memory in context, copies data from host.
         * @tparam T Array type.
         * @param data Array to copy to device
         * @param size Array size
         */
        template<typename T>
        CudaDeviceMemory<T> allocDevice(T *data, int size) {
            CudaDeviceMemory<T> mem(size);
            mem.copyHostDevice(data);
        }

        /*!
         * @brief Allocates host memory in context.
         * @tparam T Array type.
         * @param size Array size.
         */
        template<typename T>
        CudaHostMemory<T> allocHost(int size) {
            return CudaHostMemory<T>(size);
        }

        /*!
         * @brief Synchronizes the context.
         */
        void synchronize() {
            CudaException::tryCuda(cuCtxSynchronize());
        }

        ~CudaContext() {
            if (!preserve && context != nullptr) {
                CudaException::tryCuda(cuCtxDestroy(context));
            }
        }

        /*!
         * @brief Preserve the context after object destruction
         * @warning May lead to memory leaks.
         * @param val set to true iff you want to preserve the context.
         */
        void setPreserve(bool val) {
            preserve = val;
        }

        /*!
         * @brief Returns ammount of free memory in context.
         */
        size_t getFreeMemory() {
            size_t free, total;
            CudaException::tryCuda(cuMemGetInfo(&free, &total));
            return free;
        }

        /*!
         * @brief Returns ammount of memory in context.
         */
        size_t getTotalMemory() {
            size_t free, total;
            CudaException::tryCuda(cuMemGetInfo(&free, &total));
            return total;
        }

        /*!
         * @brief Wraps existing context in a dummy CudaContext object.
         * @warning Does not create a cuda context itself, use with caution.
         */
        static CudaContext getExistingContext() {
            return {};
        }

        friend class CudaDevice;
    };


    /*!
     * @class CudaDevice
     * @brief Represents a single cuda device.
     */
    class CudaDevice {
    private:
        CUdevice device = 0;

        explicit CudaDevice(int num) {
            CudaException::tryCuda(cuDeviceGet(&device, num));
        }

    public:
        /*!
         * @brief Creates a new CudaContext.
         * @param flags Context creation flags.
         */
        CudaContext createContext(unsigned flags = 0) {
            return CudaContext(device, flags);
        }

        friend class CudaDriver;
    };

    /*!
    * @class CudaDimensions
    * @brief 3D dimennsions array { x, y, z }
    */
    typedef std::array<unsigned, 3> CudaDimensions;

    /*!
     * @class CudaKernelArgs
     * @brief Arguments passed to launched CudaKernel.
     */
    class CudaKernelArgs {
    private:
        void **argsPtr = nullptr;
    public:
        ~CudaKernelArgs() {
            delete argsPtr;
        }

        /*!
         * @brief Recommended constructor.
         * @param args List of CudaMemory object to pass to kernel.
         */
        CudaKernelArgs(std::initializer_list<CudaMemory *> args) {
            argsPtr = new void *[args.size()];
            int i = 0;
            for (auto &a : args) {
                argsPtr[i++] = a->getRaw();
            }
        }

        /*!
         * @brief Wraps c-style argument list.
         * @param args Array of pointers to arguments to pass to kernel.
         */
        explicit CudaKernelArgs(void **args) {
            argsPtr = args;
        }

        /*!
         * @brief Returns c-style argument list.
         */
        void **getArgs() {
            return argsPtr;
        }
    };

    /*!
     * @class CudaKernelExtraArgs
     * @brief Additional launch parameters for CudaKernel, usually unrequired.
     */
    struct CudaKernelExtraParams {
        /*!
         * Dynamic shared-memory size per thread block in bytes.
         */
        unsigned sharedBytes = 0;
        /*!
         * Stream identifier.
         */
        CUstream hStream = nullptr;
        /*!
         * Extra options.
         */
        void **extra = nullptr;

        static CudaKernelExtraParams getDefaultInstance() {
            return {};
        };
    };

    /*!
     * @class CudaKernel
     * @brief A cuda kernel, can be launched within the current context with CudaKernel::launch.
     */
    class CudaKernel {
    private:
        CUfunction kernel = nullptr;

        CudaKernel(const char *name, CUmodule module) {
            CudaException::tryCuda(cuModuleGetFunction(&kernel, module, name));
        }

    public:
        /*!
         * Launches the kernel.
         * @param grid Number of blocks in grid.
         * @param block Number of threads to spawn in each block.
         * @param args Kernel parameters.
         * @param extraArgs Additional launch parameters, usually unrequired.
         */
        void launch(CudaDimensions grid, CudaDimensions block, CudaKernelArgs args,
                    CudaKernelExtraParams extraArgs = CudaKernelExtraParams::getDefaultInstance()) {
            CudaException::tryCuda(
                    cuLaunchKernel(kernel, grid[0], grid[1], grid[2], block[0], block[1], block[2],
                                   extraArgs.sharedBytes,
                                   extraArgs.hStream, args.getArgs(), extraArgs.extra));
        }

        friend class CudaModule;
    };

    /*!
     * @class CudaModule
     * @brief Represents a single cuda code module, allows extraction of cuda kernels included in it.
     */
    class CudaModule {
    private:
        CUmodule module = nullptr;

        explicit CudaModule(const char *name) {
            CudaException::tryCuda(cuModuleLoad(&module, name));
        }

    public:
        /*!
         * @brief Loads CudaKernel from module.
         * @param name name of kernel to load.
         */
        CudaKernel getKernel(const char *name) {
            return {name, module};
        }

        friend class CudaDriver;
    };

    /*!
     * @class CudaDriver
     * @brief Root for all interactions with cuda driver api, represents the driver itself.
     */
    class CudaDriver {
    private:
        int deviceCount = 0;

        CudaDriver() {
            CudaException::tryCuda(cuDeviceGetCount(&deviceCount));
        }

    public:
        /*!
         * @brief Returns handle for specified device.
         * @param deviceNumber number of the device to get.
         */
        CudaDevice getDevice(int deviceNumber) {
            return CudaDevice(deviceNumber);
        }

        /*!
         * @brief Returns handle for a cuda device, if more than one is avilable returns random one.
         */
        CudaDevice getDevice() {
            if (deviceCount == 0) {
                throw CudaException(CUDA_ERROR_NO_DEVICE);
            } else if (deviceCount == 1) {
                return getDevice(0);
            }
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0, deviceCount - 1);
            return getDevice(distribution(generator));
        }

        /*!
         * @brief Loads cuda code module.
         * @param modulePath path to the ptx file.
         */
        CudaModule getModule(const char *modulePath) {
            return CudaModule(modulePath);
        }

        /*!
         * @brief CudaDriver factory, initializes Driver API when called the first time.
         */
        static CudaDriver getInstance() {
            static bool isInitialized;
            if (!isInitialized) {
                CudaException::tryCuda(cuInit(0));
                isInitialized = true;
            }
            return {};
        }

        /*!
         * @brief Returns CudaDriver object WITHOUT initializing Driver API.
         * @warning Does not initialize Driver API.
         */
        static CudaDriver getExistingInstance() {
            return {};
        }
    };
}
