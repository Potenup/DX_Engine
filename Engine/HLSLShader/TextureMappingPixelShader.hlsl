struct PixelInput
{
    float4 position : SV_Position;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
};

// Texture.
Texture2D diffuseMap : register(t0);
SamplerState diffuseSamler : register(s0);

float4 main(PixelInput input) : SV_TARGET
{
    // sampling.
    float4 texColor = diffuseMap.Sample(diffuseSamler, input.texCoord);
	//return float4(1.0f, 0.0f, 0.0f, 1.0f);
    // return float4(input.color, 1.0f);
    return float4(texColor);
}