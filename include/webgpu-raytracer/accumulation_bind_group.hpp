#pragma once

#include <webgpu.h>

WGPUBindGroupLayout createAccumulationSampleBindGroupLayout(WGPUDevice device);
WGPUBindGroupLayout createAccumulationStorageBindGroupLayout(WGPUDevice device, WGPUTextureFormat textureFormat);

WGPUBindGroup createAccumulationSampleBindGroup(WGPUDevice device, WGPUBindGroupLayout bindGroupLayout, WGPUTextureView accumulationTextureView);
WGPUBindGroup createAccumulationStorageBindGroup(WGPUDevice device, WGPUBindGroupLayout bindGroupLayout, WGPUTextureView accumulationTextureView);
