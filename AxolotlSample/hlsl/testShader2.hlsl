struct Vertex
{
    float4 Position : SV_POSITION;
    float4 Color : COLOR0;
};

float4 frag(Vertex input) : SV_Target0
{
    float d = dot(input.Position, input.Color);

    return float4(d,d,d,d);
}