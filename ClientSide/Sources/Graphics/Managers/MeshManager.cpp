/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "MeshManager.hpp"

GLvoid Graphics::Managers::MeshManager::initializeMeshes() noexcept
{
    mMeshes[TREE] = createMesh(u8"Tree\\Tree.obj");
    mMeshes[CUBE] = createMesh(u8"Cube.obj");
    mMeshes[GROUND_POLYGON] = createMesh(u8"Ground\\Ground.obj");
}

Graphics::Components::Mesh Graphics::Managers::MeshManager::createMesh(const char* modelName) noexcept
{
    String modelFullPath(Configuration::getModelsPath());
    modelFullPath.append(modelName);
    return Tools::ObjParser(mMeshesAllocator).parse(modelFullPath);
}

Graphics::Components::Mesh& Graphics::Managers::MeshManager::getMesh(EMeshType meshType) noexcept
{
    return mMeshes[meshType];
}

Graphics::Managers::MeshManager::~MeshManager()
{
    for (GLubyte i = 0; i < COUNT_MESH_TYPES; i++)
        mMeshes[i].destroy();
}
