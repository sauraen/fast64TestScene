void Scene_DrawConfigPotionShopGranny(PlayState* play) {
    u32 gameplayFrames;
    u32 i;
    Gfx *effectsList;
    static u32 lastEyes = 0;

    OPEN_DISPS(play->state.gfxCtx, "fast64TestScene", 0);

    gameplayFrames = play->gameplayFrames;
    effectsList = Graph_Alloc(play->state.gfxCtx, 2 * sizeof(Gfx));
    gSPSegment(POLY_OPA_DISP++, 0x0D, effectsList);
    
    // Traffic light
    i = gameplayFrames & 63;
    if(i < 30){
        i = 2;
    }else if(i < 45){
        i = 1;
    }else{
        i = 0;
    }
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sFlipCI4Textures[i]));
    
    // Eyes
    i = gameplayFrames;
    i ^= i >> 16;
    i *= 0x45d9f3b;
    i ^= i >> 16;
    i ^= i >> 8;
    i ^= i >> 4;
    i = lastEyes + 1 + (i & 3);
    if(i >= 5) i -= 5;
    if(i >= 5) i = 0;
    lastEyes = i;
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sFlipIA8Textures[i]));
    
    // Ocean
    i = (gameplayFrames >> 4) & 1;
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(sFlipTwoCI4Textures[i]));
    // Boat
    i = 63 - ((gameplayFrames >> 2) & 63);
    gDPSetTileSize(effectsList + 0, 1, i*4, 0, (i+63)*4, 15*4);
    gSPEndDisplayList(effectsList + 1);
    
    CLOSE_DISPS(play->state.gfxCtx, "fast64TestScene", 0);
}
