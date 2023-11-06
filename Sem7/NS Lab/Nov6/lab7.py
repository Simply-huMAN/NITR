import xml.etree.ElementTree as ET

# Parse the XML file
tree = ET.parse('manet-routing-compare.flowmon')
root = tree.getroot()

# Find the required information
for flow in root.iter('flow'):
    flowId = flow.find('flowId').text
    source_address = flow.find('source-address').text
    destination_address = flow.find('destination-address').text
    flowBitRates = flow.find('flowBitRates').text
    delayMean = flow.find('delayMean').text
    txBitrate = flow.find('txBitrate').text
    rxBitrate = flow.find('rxBitrate').text
    PacketLossRatio = flow.find('PacketLossRatio').text

    # Print the results
    print('Flow ID:', flowId)
    print('Source Address:', source_address)
    print('Destination Address:', destination_address)
    print('Flow Bit Rates:', flowBitRates)
    print('Delay Mean:', delayMean)
    print('TX Bitrate:', txBitrate)
    print('RX Bitrate:', rxBitrate)
    print('Packet Loss Ratio:', PacketLossRatio)

