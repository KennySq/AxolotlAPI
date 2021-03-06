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
    return float4(input.Position, 1.0f);
}