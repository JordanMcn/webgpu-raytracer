#pragma once

#include <webgpu-raytracer/shader_registry.hpp>
#include <webgpu-raytracer/scene_data.hpp>
#include <webgpu-raytracer/camera_bind_group.hpp>

#include <webgpu.h>

struct RaytraceMonteCarloPipeline
{
    RaytraceMonteCarloPipeline(WGPUDevice device, ShaderRegistry & shaderRegistry, WGPUBindGroupLayout cameraBindGroupLayout,
        WGPUBindGroupLayout geometryBindGroupLayout, WGPUBindGroupLayout materialBindGroupLayout, WGPUBindGroupLayout accumulationStorageBindGroupLayout);
    ~RaytraceMonteCarloPipeline();

    WGPUComputePipeline pipeline() const { return pipeline_; }

private:
    WGPUPipelineLayout pipelineLayout_;
    WGPUComputePipeline pipeline_;
};

void renderRaytraceMonteCarlo(WGPUCommandEncoder commandEncoder, WGPUTextureView colorTextureView, WGPUComputePipeline raytraceMonteCarloPipeline,
    WGPUBindGroup cameraBindGroup, SceneData const & sceneData, WGPUBindGroup accumulationStorageBindGroup, glm::uvec2 const & screenSize);
