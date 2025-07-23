#include <cstdio>
#include <cuda_runtime.h>
#include <fstream>
#include <iomanip>
#include <iostream>


void device_info(std::ofstream &fs) {
  int device_id;
  cudaGetDevice(&device_id);

  cudaDeviceProp props;
  cudaGetDeviceProperties(&props, device_id);

  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);

  int warps_per_sm = props.maxThreadsPerMultiProcessor / props.warpSize;

  // Assume double data rate
  double peak_mem_bw =
    2.0 * props.memoryClockRate * (props.memoryBusWidth / 8) / 1e6;  // GB/s

  oss << "Device Info\n"
      << "===========\n"
      << "Device ID                        : " << device_id << "\n"
      << "Name                             : " << props.name << "\n"
      << "Compute Capability               : " << props.major << "."
      << props.minor << "\n"
      << "Total Global Memory              : "
      << props.totalGlobalMem / (1024 * 1024) << " MB\n"
      << "Memory Bus Width                 : " << props.memoryBusWidth
      << " bits\n"
      << "Multiprocessor Count (SMs)       : " << props.multiProcessorCount
      << "\n"
      << "Max Threads per Block            : " << props.maxThreadsPerBlock
      << "\n"
      << "Max Threads per Multiprocessor   : "
      << props.maxThreadsPerMultiProcessor << "\n"
      << "Threads per Warp                 : " << props.warpSize << "\n"
      << "Estimated Warps per SM           : " << warps_per_sm << "\n"
      << "Max Registers per Block          : " << props.regsPerBlock << "\n"
      << "Max Shared Mem per Block         : " << props.sharedMemPerBlock / 1024
      << " KB\n"
      << "Shared Mem per Multiprocessor    : "
      << props.sharedMemPerMultiprocessor / 1024 << " KB\n"
      << "Constant Memory                  : " << props.totalConstMem / 1024
      << " KB\n"

    << "Memory Clock Rate                : " << props.memoryClockRate / 1000 << " MHz\n"
    << "L2 Cache Size                    : " << props.l2CacheSize / 1024 << " KB\n"
    << "Max Threads Dim (x, y, z)        : (" << props.maxThreadsDim[0] << ", "
    << props.maxThreadsDim[1] << ", " << props.maxThreadsDim[2] << ")\n"
    << "Max Grid Size (x, y, z)          : (" << props.maxGridSize[0] << ", "
    << props.maxGridSize[1] << ", " << props.maxGridSize[2] << ")\n"
    << "Unified Addressing Supported     : " << (props.unifiedAddressing ? "Yes" : "No") << "\n"
    << "Concurrent Kernels Supported     : " << (props.concurrentKernels ? "Yes" : "No") << "\n"
    << "Async Engine Count               : " << props.asyncEngineCount << "\n"
    << "Compute Mode                     : " << props.computeMode << "\n";

  std::cout << oss.str();
  fs << oss.str();

}

