/*
 * Copyright (c) Contributors, http://opensimulator.org/
 * See CONTRIBUTORS.TXT for a full list of copyright holders.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the OpenSimulator Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once
#include "GameFramework/GameMode.h"
#include "MeshActor.h"
#include "AvinationViewerGameMode.generated.h"
class ObjectCreator;

/**
 * 
 */
UCLASS()
class AVINATIONVIEWER_API AAvinationViewerGameMode : public AGameMode
{
    GENERATED_BODY()

    
    AAvinationViewerGameMode(const class FObjectInitializer& ObjectInitializer);
	virtual void HandleMatchHasStarted() override;
    virtual void Tick(float deltaSeconds) override;
    
private:
    TMap<FGuid, AMeshActor *> actors;
    TArray<rapidxml::xml_node<> *> queue;
    
    void CreateNewActor(FGuid id, TSharedAssetRef data);
    AMeshActor *CreateNewActor(rapidxml::xml_node<> *data, ObjectReadyDelegate d, AMeshActor *act = 0);
    AMeshActor *CreateNewActor(rapidxml::xml_node<> *data);
    void HandleObjectReady(AMeshActor *act);
    ObjectCreator *creator = 0;
    
    friend class ObjectCreator;
};

