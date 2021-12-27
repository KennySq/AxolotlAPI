cbuffer Constants
{
    float4x4 World;
    float4x4 View;
    float4x4 Projection;
};

struct Vertex
{
    float3 Position : POSITION0;
    float4 Color : COLOR0;
};

float4 vert(Vertex input) : SV_Position
{
    float4 world = mul(float4(input.Position, 1.0f), World);
    float4 view = mul(world, View);
    float4 projection = mul(view, Projection);
    
    return projection;
}